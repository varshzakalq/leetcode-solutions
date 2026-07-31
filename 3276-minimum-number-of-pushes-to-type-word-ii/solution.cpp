class Solution {
public:
    int minimumPushes(string word) {

        vector<int> arr(26,0);
        for(auto i:word){
            arr[i-'a']++;
        }
        // for(auto i:arr){
        //     cout<<i<<" ";
        // }
        
        //unordered_set <char> s1 = {'a','d','g','j','m','p','t','w'};
        //unordered_set <char>s2 = {'b','e','h','k','n','q','u','x'};
        //unordered_set <char>s3 = {'c','f','i','l','o','r','v','y'};
        //unordered_set <char>s4 = {'s','z'};
        //  unordered_set <char> s1;
        //  unordered_set <char>s2;
        //  unordered_set <char>s3;
        //  unordered_set <char>s4;
         int min = 0;
         int size =0;
         int container = 1;
        while (size<word.size()){
            auto max = max_element(arr.begin(),arr.end())-arr.begin();
            //cout<<arr[max];
            size += arr[max];
            if(container <9){
                min += arr[max];
            }
            else if(container >=9 && container <17){
                min += arr[max]*2;
            }
            else if(container >= 17 && container <25 ){
                min += arr[max]*3;
            }
            else{
                min += arr[max]*4;
            }
            //cout<<"contatiner:"<<container;
            arr[max] =0;
            container++;
        }
        return min;
    }
};
