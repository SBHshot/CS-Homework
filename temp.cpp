   //將string轉換為char
    int v = size.substr(3).length();
    char v_array[v + 1];
    strcpy(v_array,size.substr(3).c_str());
    cout << "size:";
    for (int i = 0; i < v; i++)
    {
        cout << v_array[i];
    }
    cout << endl;

    
    //將string轉換為char
    int m = minTerm.substr(3).length();
    char m_array[m+1];
    strcpy(m_array,minTerm.substr(3).c_str());
    cout << "min:";
    for (int i = 0; i < m; i++)
    {
        cout << m_array[i];
    }
    cout << endl;

  
    int d = don.substr(3).length();
    char d_array[256];
    strcpy(d_array,don.substr(3).c_str());
    cout << "Don't Care:";
    for (int i = 0; i < d; i++){
        cout << d_array[i];
    }
    cout << endl;
//    token = strtok(d_array, ",");
//    while (token != NULL){
//    cout << token;
//    token = strtok(NULL, ",");
//    }
    cout << d_array[1];
    /*輸出char array info*/