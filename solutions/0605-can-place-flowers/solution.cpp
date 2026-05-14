class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count =0;
        if(flowerbed[0] ==0 && n ==1 &&flowerbed.size() ==1) return true;
        for( int i =0 ; i<flowerbed.size(); i++){
            if (flowerbed[i] == 0)count++;
            else if(flowerbed[i] !=0) count =0;
            if(count == 2 && (i ==1 || i == flowerbed.size()-1)){
                count = 1; n--;
            }
            if (count == 3){
                count =1; 
                n--;
            }
        }
        if (n <=0)return true;
        else return false;
    }
};
