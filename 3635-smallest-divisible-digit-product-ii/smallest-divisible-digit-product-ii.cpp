class Solution {
public:
    int C2[10]={0,0,1,0,2,0,1,0,3,0};
    int C3[10]={0,0,0,1,0,0,1,0,0,2};
    int C5[10]={0,0,0,0,0,1,0,0,0,0};
    int C7[10]={0,0,0,0,0,0,0,1,0,0};
    int mem[47][30];

    int computeMinSlots(int a,int b){
        if(a<=0&&b<=0)return 0;
        if(a<0)a=0; if(b<0)b=0;
        int best=1e9, mx=min(a,b);
        for(int k=0;k<=mx;k++){
            int r2=a-k; if(r2<0)r2=0;
            int r3=b-k; if(r3<0)r3=0;
            int s=k+(r2+2)/3+(r3+1)/2;
            if(s<best)best=s;
        }
        return best;
    }
    int minSlots(int a,int b){
        if(a<0)a=0; if(b<0)b=0;
        if(a<47&&b<30) return mem[a][b];
        return computeMinSlots(a,b);
    }
    bool feasible(long long rem,int a,int b,int c,int d){
        if(a<0)a=0; if(b<0)b=0; if(c<0)c=0; if(d<0)d=0;
        if((long long)c+d>rem) return false;
        return (long long)minSlots(a,b) <= rem-(long long)(c+d);
    }
    string buildSmallest(int f,int a,int b,int c,int d){
        string res; res.reserve(f);
        for(int pos=0;pos<f;pos++){
            int rem=f-pos-1;
            for(int dd=1;dd<=9;dd++){
                int na=max(0,a-C2[dd]),nb=max(0,b-C3[dd]);
                int nc=max(0,c-C5[dd]),nd=max(0,d-C7[dd]);
                if(feasible(rem,na,nb,nc,nd)){
                    res.push_back(char('0'+dd));
                    a=na;b=nb;c=nc;d=nd;
                    break;
                }
            }
        }
        return res;
    }

    string smallestNumber(string num, long long t){
        for(int a=0;a<47;a++)for(int b=0;b<30;b++)mem[a][b]=computeMinSlots(a,b);
        int ta=0,tb=0,tc=0,td=0; long long tt=t;
        while(tt%2==0){tt/=2;ta++;}
        while(tt%3==0){tt/=3;tb++;}
        while(tt%5==0){tt/=5;tc++;}
        while(tt%7==0){tt/=7;td++;}
        if(tt!=1) return "-1";

        int n=num.size(), firstZero=n;
        for(int i=0;i<n;i++) if(num[i]=='0'){firstZero=i;break;}
        int upto=firstZero;
        vector<int> pA(upto+1,0),pB(upto+1,0),pC(upto+1,0),pD(upto+1,0);
        for(int j=0;j<upto;j++){
            int dig=num[j]-'0';
            pA[j+1]=pA[j]+C2[dig]; pB[j+1]=pB[j]+C3[dig];
            pC[j+1]=pC[j]+C5[dig]; pD[j+1]=pD[j]+C7[dig];
        }
        // exact match (num itself)
        if(firstZero==n && pA[n]>=ta && pB[n]>=tb && pC[n]>=tc && pD[n]>=td)
            return num;

        // case A: same length, first difference at position i
        int istart=min(n-1,firstZero);
        for(int i=istart;i>=0;i--){
            int needA=max(0,ta-pA[i]), needB=max(0,tb-pB[i]);
            int needC=max(0,tc-pC[i]), needD=max(0,td-pD[i]);
            int f=n-1-i, start=(num[i]-'0')+1;
            for(int dd=start;dd<=9;dd++){
                int na=max(0,needA-C2[dd]),nb=max(0,needB-C3[dd]);
                int nc=max(0,needC-C5[dd]),nd=max(0,needD-C7[dd]);
                if(feasible(f,na,nb,nc,nd)){
                    string res=num.substr(0,i);
                    res.push_back(char('0'+dd));
                    res+=buildSmallest(f,na,nb,nc,nd);
                    return res;
                }
            }
        }

        // case B: must grow longer
        int m=tc+td+minSlots(ta,tb);
        int L=max(n+1,m);
        return buildSmallest(L,ta,tb,tc,td);
    }
};
