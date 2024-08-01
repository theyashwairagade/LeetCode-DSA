class Solution {
    int solve(int index, int currHeight, int currWidth, int &n, vector<vector<int>> &books, int &shelfWidth){
        int bookWidth = books[index][0], bookHeight = books[index][1];
        if(index == n-1){
            if(bookWidth<=currWidth)
                return (currHeight < bookHeight) ? (bookHeight-currHeight) : 0;
            return bookHeight;
        }
        int currSelf = 1e7;
        if(currWidth>=bookWidth)
            currSelf = ((bookHeight > currHeight) ? (bookHeight-currHeight) : 0) + solve(index+1, max(bookHeight, currHeight), currWidth-bookWidth, n, books, shelfWidth);
        int newSelf = bookHeight + solve(index+1, bookHeight, shelfWidth-bookWidth, n, books, shelfWidth);
        return min(currSelf, newSelf);
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        return solve(0, 0, shelfWidth, n, books, shelfWidth);
    }
};





// Due to overlapping sub problems doing memonization
class Solution {
    int solve(int index, int currHeight, int currWidth, int &n, vector<vector<int>> &books, int &shelfWidth, vector<vector<vector<int>>> &dp){
        int bookWidth = books[index][0], bookHeight = books[index][1];
        if(index == n-1){
            if(bookWidth <= currWidth)
                return (currHeight < bookHeight) ? (bookHeight - currHeight) : 0;
            return bookHeight;
        }
        if(dp[index][currHeight][currWidth] != -1)
            return dp[index][currHeight][currWidth];
        
        int currSelf = INT_MAX;
        if(currWidth >= bookWidth)
            currSelf = ((bookHeight > currHeight) ? (bookHeight - currHeight) : 0) + solve(index + 1, max(bookHeight, currHeight), currWidth - bookWidth, n, books, shelfWidth, dp);
        
        int newSelf = bookHeight + solve(index + 1, bookHeight, shelfWidth - bookWidth, n, books, shelfWidth, dp);
        
        return dp[index][currHeight][currWidth] = min(currSelf, newSelf);
    }

    pair<int, int> find(vector<vector<int>> &books){
        pair<int, int> ans = {0, 0};
        for(auto &book: books)
            ans.first = max(ans.first, book[0]),
            ans.second = max(ans.second, book[1]);
        return ans;
    }

public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        auto maxWidthHeight = find(books);
        int maxWidth = maxWidthHeight.first, maxHeight = maxWidthHeight.second;
        vector<vector<vector<int>>> dp(n , vector<vector<int>>(maxHeight + 1, vector<int>(shelfWidth + 1, -1)));
        return solve(0, 0, shelfWidth, n, books, shelfWidth, dp);
    }
};





// Passing iterative soln to remove stack space
class Solution {
    pair<int, int> find(vector<vector<int>> &books) {
        pair<int, int> ans = {0, 0};
        for (auto &book : books) {
            ans.first = max(ans.first, book[0]);
            ans.second = max(ans.second, book[1]);
        }
        return ans;
    }

public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        auto maxWidthHeight = find(books);
        int maxHeight = maxWidthHeight.second;
        vector<vector<int>> dp(maxHeight + 1, vector<int>(shelfWidth + 1, INT_MAX));

        // Base case
        for (int currHeight = 0; currHeight <= maxHeight; currHeight++) {
            dp[currHeight][0] = 0;
        }

        for (int index = 0; index < n; index++) {
            int bookWidth = books[index][0], bookHeight = books[index][1];
            vector<vector<int>> newDp(maxHeight + 1, vector<int>(shelfWidth + 1, INT_MAX));
            
            for (int currHeight = 0; currHeight <= maxHeight; currHeight++) {
                for (int currWidth = 0; currWidth <= shelfWidth; currWidth++) {
                    if (dp[currHeight][currWidth] == INT_MAX) continue;

                    // Case 1: Place the book on the current shelf
                    if (currWidth + bookWidth <= shelfWidth) {
                        int newHeight = max(currHeight, bookHeight);
                        newDp[newHeight][currWidth + bookWidth] = min(newDp[newHeight][currWidth + bookWidth], dp[currHeight][currWidth]);
                    }

                    // Case 2: Place the book on a new shelf
                    newDp[bookHeight][bookWidth] = min(newDp[bookHeight][bookWidth], dp[currHeight][currWidth] + currHeight);
                }
            }

            dp = newDp;
        }

        // Find the minimum height from the dp array
        int minHeight = INT_MAX;
        for (int currHeight = 0; currHeight <= maxHeight; currHeight++) {
            for (int currWidth = 0; currWidth <= shelfWidth; currWidth++) {
                if (dp[currHeight][currWidth] != INT_MAX) {
                    minHeight = min(minHeight, dp[currHeight][currWidth] + currHeight);
                }
            }
        }

        return minHeight;
    }
};