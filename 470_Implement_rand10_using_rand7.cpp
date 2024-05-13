public:
    int fiver(){
        int value=rand7();
        if(value>5) return fiver();
        return value;
    }
    int rand10() {
        int value=rand7();
        if(value==4)    return rand10();
        if(value<4)     return fiver();
        else    return fiver()+5;
    }
};