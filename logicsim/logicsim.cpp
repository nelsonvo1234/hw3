#include <iostream>
#include <sstream>
#include <string>

#include "circuit.h"

using namespace std;
//hi
int main(int argc, char* argv[])
{
	stringstream ss;
  Circuit C;
  if(argc != 1)
  {
    if(C.parse(argv[1]))
    {
    	  C.startUml(ss);
        C.run(ss);
        C.endUml(ss);
        cout << ss.str() << endl;
    }
  }
  else
  {
      cout << "Please provide a circuit file to simulate." << endl;
      return 1;
  }
}
