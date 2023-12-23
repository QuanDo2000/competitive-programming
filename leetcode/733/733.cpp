#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        if (oldColor == color) return image;
        image[sr][sc] = color;
        if (sr > 0 && image[sr - 1][sc] == oldColor) floodFill(image, sr - 1, sc, color);
        if (sr < image.size() - 1 && image[sr + 1][sc] == oldColor) floodFill(image, sr + 1, sc, color);
        if (sc > 0 && image[sr][sc - 1] == oldColor) floodFill(image, sr, sc - 1, color);
        if (sc < image[0].size() - 1 && image[sr][sc + 1] == oldColor) floodFill(image, sr, sc + 1, color);
        return image;
    }
};
