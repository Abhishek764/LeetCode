class Solution {
private:

int solveMem(vector<int>& obstacles,int currpos,int currLane,vector<vector<int>> &dp)
    {
          int n=obstacles.size()-1;
          //Base case
          if(currpos==n) return 0;

          if(dp[currLane][currpos]!=-1) return dp[currLane][currpos];

          if(obstacles[currpos+1]!=currLane)
          {
            return solveMem(obstacles,currpos+1,currLane,dp);
          }else
          {

            //sideways jump
            int ans=INT_MAX;
            for(int i=1;i<=3;i++)
            {
                if(currLane!=i && obstacles[currpos]!=i)
                {
                    ans=min(ans,1+solveMem(obstacles,currpos,i,dp));
                }
            }
            dp[currLane][currpos]=ans;
            return dp[currLane][currpos];
          }
    }    

public:
    int minSideJumps(vector<int>& obstacles) {

        vector<vector<int>> dp(4,vector<int> (obstacles.size(),-1));
        return solveMem(obstacles,0,2,dp);

    }
};