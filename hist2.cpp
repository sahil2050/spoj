/*
 * In statistics, a histogram is a graphical display of tabulated frequencies, shown as bars. It shows what proportion of cases fall into each of several categories. It is a polygon composed of a sequence of rectangles aligned at a common base line. In this problem all rectangles have a width of unit length. But their heights are distinct. Some permutation of the heights will give the maximum perimeter. Your task is to find the maximum perimeter of the histogram and the number of permutations that give the maximum perimeter. 
 *
 * input: Input consists of multiple test cases. Each test case describes a histogram and starts with an integer N, 2 ≤ N ≤ 15, denoting the number of rectangles it is composed of. Next line consists of N space separated positive integers representing the heights of the rectangles. All heights are distinct and less than or equal to 100. N=0 indicates the end of tests.There are atmost 50 test cases. 
 *
 * output:For each test case output the maximum possible perimeter of the histogram and the number of permutations that give maximum perimeter in a single line, separated by a single space.
 * */


#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    if(n==0) return 0;
    
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int dp[(1<<n)][n];
    int count[(1<<n)][n];

    for(int i=0;i<n;i++){
        dp[0][i]=0;
        count[0][i]=0;
    }
    for(int mask=1;mask<(1<<n);mask++){
        for(int i=0;i<n;i++){
            if(mask==(1<<i))
                dp[mask][i]=2*arr[i]+2;
            else
                dp[mask][i]=0;
            count[mask][i]=1;
            if(mask&(1<<i)){
                for(int k=0;k<n;k++){
                    if((mask&(1<<k))&&(k!=i)){
                        int temp=dp[mask-(1<<i)][k]+abs(arr[i]-arr[k])+arr[i]-arr[k]+2;
                        if(dp[mask][i]<temp){
                            dp[mask][i]=temp;
                            count[mask][i]=count[mask-(1<<i)][k];
                        }
                        else if(dp[mask][i]==temp){
                            count[mask][i]+=count[mask-(1<<i)][k];
                        }
                    }
                }
            }
        }
    }
    
    /*for(int mask=1;mask<(1<<n);mask++){
          for(int i=0;i<n;i++){
              cout<<dp[mask][i]<<" ";
          }
          cout<<endl;
    }
    */

    int ans=0;
    int count_ans=1;
    for(int i=0;i<n;i++){
        if(ans<dp[(1<<n)-1][i]){
            ans=dp[(1<<n)-1][i];
            count_ans=count[(1<<n)-1][i];
        }
        else if(ans==dp[(1<<n)-1][i]){
            count_ans+=count[(1<<n)-1][i];
        }
    }
    cout<<ans<<" "<<count_ans<<endl;
    return main();
}
