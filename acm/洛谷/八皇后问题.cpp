#include<bits/stdc++.h>

using namespace std;

int col[13]={0};  //col数组用于存放第i行第col[i]列放置皇后。
int n,tot = 0;		//设置全局变量，即可不用投值，直接调用
bool check(int r,int c){		//判断新皇后是否和放好的皇后发生冲突。
    for(int i=0;i<r;i++){
    	//这里不需要判断是否同行，因为我们设置的每行只投放一个皇后，所以不需要判断，只判断是否同列或者同斜线即可。
        if((col[i]==c)||(abs(col[i]-c)==abs(i-r)))return false;
    }
    return true;
}
void dfs(int r){
    if(r==n){ //因为从0开始，当行数r达到n时，表示已经完成了
        tot++;
        return ;
    }
    for(int c=0;c<n;c++){
        if(check(r,c)){ //判断是否可以放置，可以便放置，否则剪枝。
            col[r]=c;
            dfs(r+1);	//继续放置下一行的新皇后
        }
    }
}
int main(){
    int ans[13]={0};
    
    for(n=0;n<=13;n++){			 //对n皇后进行打表，然后结果存入ans数组
        memset(col,0,sizeof(col)); 	//每次要进行初始化
        tot=0;
        dfs(0);					//DFS
        ans[n]=tot;				//存放
    }
    while(cin >> n){
        if(n==0)return 0;
        cout << ans[n] << endl;
    }
    return 0;
}

