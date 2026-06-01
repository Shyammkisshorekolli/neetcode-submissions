class Solution {
public:
    vector<int>lens;
    string encoded_string="";
    vector<string>decoded_strs;
    int j=0;
    string encode(vector<string>& strs) {
        for(int i=0;i<strs.size();i++){
            lens.push_back(strs[i].length());
            encoded_string=encoded_string+strs[i];
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        for(int i=0;i<lens.size();i++){
            int k=lens[i];
            int j_=j+k;
            string news="";
            for(;j<j_;j++){
                news=news+encoded_string[j];
            }
            decoded_strs.push_back(news);
        }
        return decoded_strs;
    }
};
