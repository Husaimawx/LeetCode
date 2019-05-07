class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        if(deck.size() == 1)
            return deck;
        vector<int> seq;
        vector<int> temp = deck;
        int from = 0;
        for(int i = 0;i<deck.size();i++) {
            seq.push_back(temp[from]);
            temp.push_back(temp[from+1]);
            from+=2;
        }
        map<int,int> M;
        vector<int> temp2 = deck;
        sort(temp2.begin(),temp2.end());
        for(int i = 0;i<deck.size();i++) {
            M[seq[i]] = temp2[i];
        }
        for(int i = 0;i<deck.size();i++) {
            deck[i] = M[deck[i]];
        }
        return deck;
    }
};