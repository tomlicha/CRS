//----------------------------------------------------------------------------

#include "image.hpp"

Pixel *
loadImage(int &out_width,
          int &out_height,
          const std::string &fileName)
{
int fd{crs::openR(fileName)};
for(int state{0};state<3;)
  {
  auto l{crs::readLine(fd)};
  const int pos{crs::find(l,'#')};
  if(pos!=-1) { l.resize(pos); }
  l=crs::strip(l);
  if(l.empty()) { continue; }
  switch(state)
    {
    case 0:
      {
      if(l!="P6")
        { throw std::runtime_error("P6 expected"); }
      ++state;
      break;
      }
    case 1:
      {
      if(crs::extract(l,out_width,out_height)!=2)
        { throw std::runtime_error("width and height expected"); }
      ++state;
      break;
      }
    case 2:
      {
      if(l!="255")
        { throw std::runtime_error("255 expected"); }
      ++state;
      break;
      }
    }
  }
const int size{out_width*out_height};
Pixel *image{new Pixel[size]};
crs::readAll(fd,image,size*int(sizeof(*image)));
crs::close(fd);
return image;
}

void
saveImage(const Pixel *image,
          int width,
          int height,
          const std::string &fileName)
{
int fd{crs::openW(fileName)};
crs::write(fd,crs::txt("P6\n% %\n255\n",width,height));
crs::writeAll(fd,image,width*height*int(sizeof(*image)));
crs::close(fd);
}

ImageSequence::ImageSequence(const std::vector<std::string> &cmdLine,
                             int count) noexcept
: _loaded{}
, _count{count}
, _current{-1}
{
for(int i=1;i<crs::len(cmdLine);++i)
  {
  const auto &f{cmdLine[i]};
  if(crs::isFile(f)&&crs::access(f,R_OK))
    {
    crs::out("loading image % ",f);
    int width,height;
    Pixel *image{loadImage(width,height,f)};
    crs::out("(% x %)\n",width,height);
    _loaded.push_back({std::unique_ptr<Pixel[]>(image),width,height});
    }
  }
}

Pixel * // image data or nullptr
ImageSequence::next(int &out_width,
                    int &out_height) noexcept
{
if(_loaded.empty()||(++_current>=_count)) { return nullptr; }
auto &info{_loaded[_current%int(_loaded.size())]};
out_width=info.width;
out_height=info.height;
return info.image.get();
}

//----------------------------------------------------------------------------
