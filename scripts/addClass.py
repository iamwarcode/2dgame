import os
import sys

if len(sys.argv) < 2:
  print "Usage python addClass.py <Class Name>"
  sys.exit(10)

include_dir = os.environ['GDIR']+"/include/"
src_dir = os.environ['GDIR']+"/src/"

header_str = sys.argv[1]+".h"
cpp_str = sys.argv[1]+".cpp"

def header(cls):
  header_src = """#ifndef %s
#define %s
    
class %s{
  public:
    %s();
    ~%s();
};
    
#endif
  """
  cls = cls.capitalize()
  header_src = header_src %(cls.upper()+"_H", cls.upper()+"_H", cls, cls, cls)
  
  return header_src
  
def source(cls):
  class_src = """#include <%s>
    
%s::%s(){
    
}
    
%s::~%s(){
    
}
  """  
  cls = cls.capitalize()
  
  class_src = class_src %(header_str, cls, cls, cls, cls)
  
  return class_src

f = open(include_dir+header_str, 'w')
f.write(header(sys.argv[1]))
f.close()

f = open(src_dir+cpp_str, 'w')
f.write(source(sys.argv[1]))
f.close()
