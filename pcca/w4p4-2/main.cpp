#include<cstdio>
#include<algorithm>
using namespace std;
int a,b,gcd,x,y,A,B;
long long ans;
inline int exgcd(int x, int y, int&a, int&b)  {
    if(y==0){
        a=1,b=0;
        return x;
    }
    int g=exgcd(y,x%y,a,b);
    int t=a;
    a=b;
    b=t-x/y*b;
    return g;
}
int main(){

    freopen("123.txt","r",stdin);
    freopen("out2.txt","w", stdout);

    scanf("%d%d",&x,&y);
    if((x==1)&&(y==1)){
        printf("1");
        return 0;
    }
    if((x==1)||(y==1)){
        printf("2");
        return 0;
    }
    int gcd=exgcd(x,y,a,b);
    ans=1LL*x*y/gcd;
    if(gcd>1){
        printf("%I64d",ans);
        return 0;
    }
    if(a>0)ans=min(ans,1LL*a*x);
    else ans=min(ans,1LL*b*y);
    printf("%I64d\n",ans);
}
