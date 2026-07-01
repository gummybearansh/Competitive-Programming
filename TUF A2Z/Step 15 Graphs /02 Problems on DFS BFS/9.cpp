// LC127 Word Ladder
// very hard problem
#include <bits/stdc++.h>
using namespace std;


int ladderLength(string beginWord, string endWord, vector<string>& wordList){
  // make a set out of the wordList
  set<string> st(wordList.begin(), wordList.end());

  // make sure the required word exists
  if (st.find(endWord) == st.end()) return 0;

  // initial set up
  // {word, sequence}
  queue<pair<string, int>>q;
  q.push({beginWord, 1});
  st.erase(beginWord);

  while (!q.empty()){ //n
    string word = q.front().first;
    int steps = q.front().second;
    q.pop();

    if (word == endWord) return steps;

    // now i will try all possible combinations i can make with this word changing a single letter
    for (int i = 0; i < word.size(); i++){//w
      // i need to keep track of original because i'll be changing it 
      char original = word[i];
      for (char ch = 'a'; ch <= 'z'; ch++){//1 (26)
        word[i] = ch;

        if (st.find(word) != st.end()){
          // now i'll just add it to my queue, and i'll never want to reach this word again (this is the shortest path to reach it) 
          st.erase(word);
          q.push({word, steps + 1});  
        }
      }
      // now i replace it back
      word[i] = original;
    }
  }

  // means i could not find a path to the end word
  return 0;
}

