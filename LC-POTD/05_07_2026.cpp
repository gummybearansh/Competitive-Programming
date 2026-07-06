class Solution {
public:
  int n;
  int MOD = 1e9 + 7;
  // memoisation
  vector<vector<pair<int, int>>> t;

  int getIntFromChar(char ch) {
    return ch != 'S' ? ch - '0' : 0;
  }

  bool isValid(int i, int j, vector<string> &board) {
    if (i >= 0 && i < n && j >= 0 && j < n && board[i][j] != 'X')
      return true;
    else
      return false;
  }

  // returns {BestScore, NumPaths}
  pair<int, int> solve(int i, int j, vector<string> &board) {
    // base case - reached the end
    // contributes 0 score, but 1 path was found
    if (board[i][j] == 'E')
      return {0, 1};

    // obstacle - return 0 score, and 0 paths
    if (board[i][j] == 'X')
      return {0, 0};

    // is this done before?
    if (t[i][j] != make_pair(-1, -1)) {
      return t[i][j];
    }

    int upScore = 0, upPaths = 0;
    int leftScore = 0, leftPaths = 0;
    int diagScore = 0, diagPaths = 0;

    char ch = board[i][j];

    // up
    if (isValid(i - 1, j, board)) {
      auto [score, paths] = solve(i - 1, j, board);
      upScore = score;
      upPaths = paths;

      if (upPaths > 0) {
        upScore += getIntFromChar(ch);
      }
    }

    // left
    if (isValid(i, j - 1, board)) {
      auto [score, paths] = solve(i, j - 1, board);
      leftScore = score;
      leftPaths = paths;

      if (leftPaths > 0) {
        leftScore += getIntFromChar(ch);
      }
    }

    // diag
    if (isValid(i - 1, j - 1, board)) {
      auto [score, paths] = solve(i - 1, j - 1, board);
      diagScore = score;
      diagPaths = paths;

      if (diagPaths > 0) {
        diagScore += getIntFromChar(ch);
      }
    }

    int bestScore, bestPaths;
    if (upScore == leftScore && leftScore == diagScore) {
      bestScore = upScore;
      bestPaths = upPaths + leftPaths + diagPaths;
    } else if (upScore == leftScore) {
      bestScore = upScore;
      bestPaths = upPaths + leftPaths;
      if (diagScore > bestScore || (diagScore == bestScore && diagPaths > bestPaths)) {
        bestScore = diagScore;
        bestPaths = diagPaths;
      }
    } else if (leftScore == diagScore) {
      bestScore = leftScore;
      bestPaths = leftPaths + diagPaths;
      if (upScore > bestScore || (upScore == bestScore && upPaths > bestPaths)) {
        bestScore = upScore;
        bestPaths = upPaths;
      }
    } else {
      bestScore = upScore;
      bestPaths = upPaths;
      if (leftScore > bestScore || (leftScore == bestScore && leftPaths > bestPaths)) {
        bestScore = leftScore;
        bestPaths = leftPaths;
      }
      if (diagScore > bestScore || (diagScore == bestScore && diagPaths > bestPaths)) {
        bestScore = diagScore;
        bestPaths = diagPaths;
      }
    }

    t[i][j] = {bestScore, bestPaths % MOD};
    return t[i][j];
  }

  vector<int> pathsWithMaxScore(vector<string> &board) {
    n = board.size();
    t.assign(n, vector<pair<int, int>>(n, {-1, -1}));

    pair<int, int> result = solve(n - 1, n - 1, board);

    return {result.first, result.second};
  }
};
