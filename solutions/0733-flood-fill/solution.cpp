class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color == image[sr][sc]) return image;
        queue <pair<int,int>>q;
        q.push({sr,sc});

        int n = image.size();
        int m = image[0].size();
        int scol = image[sr][sc];
        while(!q.empty()){
            image[q.front().first][q.front().second] = color;
            int sr =q.front().first;
            int sc = q.front(). second;
            q.pop();
            if(sr>0&&image[sr-1][sc]==scol){
                q.push({sr-1,sc});

            }
            if(sc>0 &&image[sr][sc-1]== scol){
                q.push({sr,sc-1});
            }
            if(sc<m-1 &&image[sr][sc+1]==scol){
                q.push({sr,sc+1});
            }
            if(sr<n-1 &&image[sr+1][sc]==scol){
                q.push({sr+1,sc});
            }
            

        }
        return image;
    }
};
