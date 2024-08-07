class Solution {
private:
    string helper(int digit, int pos, unordered_map<int, string>&mpp){
        string str="";
        if(pos==0){
            str+=mpp[digit]+" Hundred";
        }
        else if(pos==1){
            str+=mpp[digit*10];
        }
        else{
            str+=mpp[digit];
        }
        return str;
    }
public:
    string numberToWords(int num) {
        if(num==0)return "Zero";
        unordered_map<int, string>mpp;
        mpp[1]="One";
        mpp[2]="Two";
        mpp[3]="Three";
        mpp[4]="Four";
        mpp[5]="Five";
        mpp[6]="Six";
        mpp[7]="Seven";
        mpp[8]="Eight";
        mpp[9]="Nine";
        mpp[10]="Ten";
        mpp[11]="Eleven";
        mpp[12]="Twelve";
        mpp[13]="Thirteen";
        mpp[14]="Fourteen";
        mpp[15]="Fifteen";
        mpp[16]="Sixteen";
        mpp[17]="Seventeen";
        mpp[18]="Eighteen";
        mpp[19]="Nineteen";
        mpp[20]="Twenty";
        mpp[30]="Thirty";
        mpp[40]="Forty";
        mpp[50]="Fifty";
        mpp[60]="Sixty";
        mpp[70]="Seventy";
        mpp[80]="Eighty";
        mpp[90]="Ninety";

        int arr[10]={0};
        int i=9;
        int n=num;
        while(n>0){
            int digit = n%10;
            arr[i--]=digit;
            n/=10;
        }
        string ans ="";
        for(int i=0;i<10;){
            if(i==0 && arr[i]!=0){
                ans = ans + mpp[arr[i]] + " Billion ";
            }

            else if(i>=1 && i<=3 && arr[i]!=0){
                if(i==2 && arr[2]==1){
                    int num = arr[2]*10+arr[3];
                    ans+=mpp[num]+" Million ";
                    i+=2;
                    continue;
                }
                ans+= helper(arr[i], i-1, mpp) + " ";
            } 
            if(i==3 && (arr[1]!=0 || arr[2]!=0 || arr[3]!=0))ans+="Million ";
            
            else if(i>=4 && i<=6 && arr[i]!=0){
                if(i==5 && arr[5]==1){
                    int num = arr[5]*10+arr[6];
                    ans+=mpp[num]+" Thousand ";
                    i+=2;
                    continue;
                }
                ans+= helper(arr[i], i-4, mpp) + " ";
            }
            if(i==6 && (arr[4]!=0 || arr[5]!=0 || arr[6]!=0))ans+="Thousand ";

            else if(i>=7 && i<=9 && arr[i]!=0){
                if(i==8 && arr[i]==1){
                    int num = arr[8]*10+arr[9];
                    ans+=mpp[num];
                    i+=2;
                    continue;
                }
                ans+= helper(arr[i], i-7, mpp);
                if(i!=9)ans+=" ";
            }
            i++;
        }
        if(ans[ans.length()-1]==' ')return ans.substr(0, ans.length()-1);
        return ans;
    }
};