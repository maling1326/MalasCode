#include <iostream>
using namespace std;

int main() {
    int SBass  {0}, EBass  {0},
        SDrum  {0}, EDrum  {0},
        SGitar {0}, EGitar {0},
        SVokal {0}, EVokal {0}, t {0};

    cin >> SBass >> EBass >> SDrum >> EDrum >> SGitar >> EGitar >> SVokal >> EVokal;

    for (int i = SGitar; i < (EGitar); ++i) {
        if (SBass  <= i && EBass  > i) continue; 
        if (SDrum  <= i && EDrum  > i) continue; 
        if (SVokal <= i && EVokal > i) continue; 
        t++;
    }

    if (t == 0) 
        cout << "No guitar solo :(";
    else 
        cout << "Guitar solo (" << t <<  " sec.)"; 

    return 0;
}