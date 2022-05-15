class Solution {
public:
  // calculating longest common subsequence of two strings using bottom up approach
    int Lcs(string A, string B, int x, int y){
    int t[501][501];
    for(int i = 0; i<x+1; i++){
            for(int j = 0;j<y+1; j++){
               // if the strings are empty, the no of common subsequence will be 0
                if(i==0 || j==0){
                    t[i][j] = 0;
                }
            }
        }
        //filling other rows and columns of the matrix
    for(int i = 1; i<x+1; i++){
        for(int j = 1;j<y+1; j++){
          // if the elements of both the string are same, add 1 and check for the rest
            if(A[i-1] == B[j-1]){
                t[i][j] = 1+ t[i-1][j-1];
            }
            else{
              // if not same then do the max of both the possibilities
                t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    return t[x][y];
}
// reversing the string
string reverse(string str){
    int n = str.length();
    for(int i = 0; i<n/2;i++){
        swap(str[i],str[n-i-1]);
    }
    return str;
}
    int minInsertions(string s) {
    int m = s.length();
    string B = reverse(s);
    int n = B.length();
      // minimum no of insertion can be calculated by subtracting longest palindromic subsequence of string s from the length of the string.
      //and longest palindromic subsequence of a string can be obtained by calculating longest common subsequence of the string and its reverse.
    return m - Lcs(s, B,m,n);
    }
};
