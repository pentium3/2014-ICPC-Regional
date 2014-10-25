#include <fstream>

using namespace std;

int main() {
    ifstream fin ("energy.in");
    ofstream fout ("energy.out");
    int n,e[201],e_max[201][201],ans=0;
    fin >> n;
    for (int i=1;i<=n;i++) {
        fin >> e[i];
        e[i+n]=e[i];
    }
    memset(e_max,0,sizeof(e_max));
    for (int i=2;i<n+n;i++) for (int j=i-1;j>=1 && i-j<n;j--) {
        for (int k=j;k<i;k++) {
            int tem=e_max[j][k]+e_max[k+1][i]+e[j]*e[k+1]*e[i+1];
            if (tem>e_max[j][i]) e_max[j][i]=tem;
        }
        if (e_max[j][i]>ans) ans=e_max[j][i];
    }
    fout << ans << endl;
    fin.close();
    fout.close();
    return 0;
}
