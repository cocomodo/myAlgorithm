    int ansval=*max_element(minArray+1,minArray+n);
    for(int i=1; i<=n; i++){
        if(minArray[i]==ansval)
        {
            cout<<i<<'\n';
            cout<<ansval;
            return 0;
        } 
    }