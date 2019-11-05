// 1197. Minimum Knight Moves
// User Accepted: 569
// User Tried: 1067
// Total Accepted: 586
// Total Submissions: 3355
// Difficulty: Medium
// In an infinite chess board with coordinates from -infinity to +infinity, you have a knight at square [0, 0].

// A knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.



// Return the minimum number of steps needed to move the knight to the square [x, y].  It is guaranteed the answer exists.





#include<bits/stdc++.h>
using namespace std;

class helper{
    public:
    int x;
    int y;
    int level;
    helper(int x,int y ,int level)
    {
        this->x=x;
        this->y  =y;
        this->level  = level;
    }
};

vector<int> xx {1,2,1,2,-1,-2,-1,-2};
vector<int>yy {2,1,-2,-1,2,1,-2,-1};

int solve(int x , int y )
{

    vector<vector<bool>>visited(400,vector<bool>(400,0));
    x=abs(x);
    y = abs(y);
    queue<helper*>q;
    q.push(new helper(0,0,1));
    while(1){
        helper* rem  = q.front();q.pop();
        if(rem->x==x&&rem->y ==y)
            return rem->level;
        if(visited[rem->x<0?300+abs(rem->x):rem->x][rem->y<0?300+abs(rem->y):rem->y] || (abs(rem->x)+abs(rem->y)>300) ||(rem->x<-10)||rem->y<-10||rem->x>x+20||rem->y>y+20)
            continue;
        visited[rem->x<0?300+abs(rem->x):rem->x][rem->y<0?300+abs(rem->y):rem->y]=1;
        for(int i =0;i<8;i++)
        {
            int nx = (rem->x+xx[i]);
            int ny = (rem->y+yy[i]);
            if(!visited[ nx<0?300+abs(nx):nx][ny<0?300+abs(ny):ny])
                q.push(new helper(rem->x + xx[i], rem->y + yy[i],rem->level+1));
        }

    } 
    return -1;
}
int main(){
    int x,y;
    cin>>x>>y;
    cout<<solve(x,y);
}