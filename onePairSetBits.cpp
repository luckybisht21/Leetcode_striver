class Solution {
public:
    bool consecutiveSetBits(int n) {
        bitset<20>b(n);
        int count=0;
        for(int i=0;i<b.size()-1;i++){
            if(b[i]==1 && b[i+1]==1){
                count++;
                //i=i+1;
            }
            
        }
        if(count ==1) {
            return true;
        }
        else return false;
    }
};