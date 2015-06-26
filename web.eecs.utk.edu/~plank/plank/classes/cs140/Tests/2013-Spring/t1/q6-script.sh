if [ $# -ne 2 ]; then
  echo "usage sh q6-script.sh header(1-3) implementation(A-F)" >&2
  exit 1
fi

h=$1
i=$2

echo "#include <iostream>" > q6-test.cpp
echo "#include <vector>" >> q6-test.cpp
echo "#include <list>" >> q6-test.cpp
echo "using namespace std;" >> q6-test.cpp
echo '#include "header-'$h'.h"' >> q6-test.cpp
echo "" >> q6-test.cpp
cat q6$i.cpp >> q6-test.cpp
cat q6-$h-main.cpp >> q6-test.cpp

echo "Header $h.  Implementation $i"
echo ""

g++ q6-test.cpp 2> q6-out.txt

if [ `wc q6-out.txt | awk '{ print $1 }'` -gt 0 ]; then
  echo "Compilation failed:"
  echo ""
  cat q6-out.txt
else
  echo "Compilation succeeded -- running"
  echo ""
  ./a.out
fi


