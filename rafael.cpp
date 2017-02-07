#include <cstdio>
#include <vector>
#include <fstream>

using namespace std;

vector<char> setmap;

void teste(vector<char> x, ofstream &myfile) {
    vector<int> tmp;

    for(int i=0; i<x.size(); i++) {
        tmp.push_back(0);
    }

    bool flag = true;

    do {
        for(int i=0; i<tmp.size(); i++) {
            printf("%c", setmap[tmp[i]]);
            myfile << setmap[tmp[i]];
        }
        printf("\n");
        myfile << "\n";

        tmp[0]++;
        for(int i=0; i<tmp.size(); i++) {
            if(tmp[i] > setmap.size() - 1) {
                tmp[i + 1]++;
                tmp[i] = 0;
            }
        }

        bool flag2 = false;
        for(int i=0; i<tmp.size(); i++) {
            if(tmp[i] < setmap.size() - 1)
                flag2 = true;
        }
        flag = flag2;
    } while(flag);

    for(int i=0; i<x.size(); i++) {
        printf("%c", setmap[tmp[i]]);
        myfile << setmap[tmp[i]];
    }
    printf("\n");
    myfile << "\n";
}

int main() {

    ofstream myfile;

    myfile.open("rafael.txt");

    setmap.push_back('A');
    setmap.push_back('B');
    setmap.push_back('C');
    setmap.push_back('D');

    vector<char> x;

    for(int i=0; i<setmap.size(); i++) {
        x.push_back('A');
        teste(x, myfile);
    }

    myfile.close();

    return 0;
}
