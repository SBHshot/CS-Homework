#include <iostream>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <string>
#include <iomanip>
#include <map>
#include <vector>
using namespace std;

int main(){
    //int i;
    //int k,j;
    //char s[50];
    //char *token;
    //int num_V;
    int num_M;
    int num_D;
    vector<string> arr;
    vector<string>::iterator it_i;
    //宣告變數(存入txt內容)
    string line;
    string size;
    string minTerm;
    string don;
    //定義橫軸與縱軸標題
    string a1 = "1";
    string a0 = "0";
    string a11 = "11";
    string a10 = "10";
    string a01 = "01";
    string a00 = "00";


    //開啟input檔案
    ifstream input("input.txt");
    if (!input){
        cout << "無法讀入檔案" << endl;
        system("pause");    
        return 0;
    } //end if
    while(getline(input,line)){
        if (line[1]=='d'){
            for (size_t i = 0; i < sizeof(line); i++){
                don = line;
            }//end for
            //cout << "Don't Care:" << don << endl;
            
        }//end if
        else if (line[1]=='v'){
            for (size_t i = 0; i < sizeof(line); i++){
                size = line;
            }
            //cout << "Size:" << size << endl;
        }//end if
        else if (line[1]=='m'){
            for (size_t i = 0; i < sizeof(line); i++){
                minTerm = line;
            }//end for
            //cout << "minTerm:" << minTerm << endl;
        }//end elif
    }//end while

    /*處理size*/
    //將string轉換為char
    int v = size.substr(3).length();
    int vsize[v];
    char *buff_v = (char *)malloc(v+1);
    memcpy(buff_v,size.substr(3).c_str(),v+1);
    for (int i = 0; i < v; i++){
        vsize[i] = atoi(buff_v);
    }//end for
    //cout << "v的個數:" << v << endl;
    //cout << "vValue:";
    //for (int i = 0; i < v; i++){
    //    cout << vsize[i] << " ";
    //}//end for
    cout << "\n";

    /*處理minTerm*/
    //利用subsbtr去除前方flag
    int m = minTerm.substr(3).length();
    int msize[m];
    char *buff_m = (char *)malloc(m+1);
    memcpy(buff_m,minTerm.substr(3).c_str(),m+1);
    char *splitStrM = strtok(buff_m,  ",");
    num_M = 0;
    while (splitStrM != NULL){
    //  cout << splitStrM << " ";
        msize[num_M] = atoi(splitStrM);
        splitStrM = strtok(nullptr, ",");
        num_M++;
    }//end while
    cout << endl;
    //for (int i = 0; i < num_M; i++){
    //    cout << msize[i] << " ";
    //}//end for
    free(buff_m);
    /*處理Don't Care*/
    //利用subsbtr去除前方flag
    int d = don.substr(3).length();
    int dsize[d];
    char *buff_d = (char *)malloc(d+1);
    memcpy(buff_d,don.substr(3).c_str(),d+1);
    char *splitStrD = strtok(buff_d,  ",");
    num_D = 0;
    while (splitStrD != NULL){
    //   cout << splitStrD << " ";
        dsize[num_D] = atoi(splitStrD);
        splitStrD = strtok(nullptr, ",");
        num_D++;
    }//end while
    //cout << endl;
    //for (int i = 0; i < num_D; i++){
    //    cout << dsize[i] << " ";
    //}
    free(buff_d);
    
    //宣告size=2時的內容
    
    string b11 = " ",b12 = " ",b21 = " ",b22 = " ";
    string c11 = " ",c12 = " ",c13 = " ",c14 = " ",c21 = " ",c22 = " ",c23 = " ",c24 = " ";
    string d11 = " ",d12 = " ",d13 = " ",d14 = " ",d21 = " ",d22 = " ",d23 = " ",d24 = " ",d31 = " ",d32 = " ",d33 = " ",d34 = " ",d41 = " ",d42 = " ",d43 = " ",d44 = " ";
    map<int, string> sizeTwo = {{0,b11},{1,b21},{2,b12},{3,b22}};
    map<int, string> sizeThree = {{0,c11},{1,c21},{2,c12},{3,c22},{4,c14},{5,c24},{6,c13},{7,c23}};
    map<int, string> sizeFour = {{0,d11},{1,d21},{2,d41},{3,d31},{4,d12},{5,d22},{6,d42},{7,d32},{8,d14},{9,d24},{10,d44},{11,d34},{12,d13},{13,d23},{14,d43},{15,d33}};
    ofstream output("output.txt");
    if (output.is_open()){
        if (vsize[0]==2){
            /* code */
            for(auto &x : sizeTwo){
                for (int i = 0; i < d; i++){
                    if (dsize[i]==x.first){
                        //x.second = "X";
                        sizeTwo[x.first] = "X";
                    }//End if
                }//End for
                for (int i = 0; i < m; i++){
                    if (msize[i]==x.first){
                        sizeTwo[x.first] = "1";
                    }//End if
                }//End for
                if(sizeTwo[x.first]== " "){
                    sizeTwo[x.first] = "0";
                }//End if
                if (sizeTwo[x.first] == "1"){
                    arr.push_back(to_string(x.first));
                    arr.push_back(",");
                }
                //cout << x.first << ":" << x.second << endl;
            }//End for
            arr.pop_back();           
            /*print to terminal*/
            /*圖表*/
            cout << "?:"<< sizeTwo[2].c_str() << endl;
            cout << "=====" << setw(1) << "Kmap" << setw(1) << "=====" <<endl;
            cout << setw(3) << "\\"<< setw(2) << "A"  << setw(1) << "|" << setw(8) << "|" << endl;
            cout << setw(2) << "B" << setw(2) << "\\" << setw(2) << "|" << setw(2) << "0" << setw(4) << a1 << setw(2) << "|"<< endl;
            cout << "-----" << setw(1) << "+"  << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" <<endl;
            cout << setw(4) << "0" << setw(2) << "|" << setw(2) << sizeTwo[0].c_str() << setw(2) << "|" << setw(2) << sizeTwo[2].c_str() << setw(2) << "|" << endl;
            cout << "-----" << setw(1) << "+"  << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" <<endl;
            cout << setw(4) << a1 << setw(2) << "|" << setw(2) << sizeTwo[1].c_str() << setw(2) << "|" << setw(2) << sizeTwo[3].c_str() << setw(2) << "|" << endl;
            cout << "-----" << setw(1) << "+"  << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" <<endl;
            cout << endl;
            cout << endl;
            /*資訊*/
            cout << "prime implcant" << endl;
            cout << "essential prime implicant:" << endl;
            cout << "F(A, B, C, D) = " << "\u03A3" << "m(";
            for(it_i=arr.begin();it_i != arr.end();++it_i) cout << *it_i;
            cout << ")" << endl;
            /*export txt*/
            /*圖表*/
            output << "?:"<< sizeTwo[2].c_str() << endl;
            output << "=====" << setw(1) << "Kmap" << setw(1) << "=====" <<endl;
            output << setw(3) << "\\"<< setw(2) << "A"  << setw(1) << "|" << setw(8) << "|" << endl;
            output << setw(2) << "B" << setw(2) << "\\" << setw(2) << "|" << setw(2) << "0" << setw(4) << a1 << setw(2) << "|"<< endl;
            output << "-----" << setw(1) << "+"  << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" <<endl;
            output << setw(4) << "0" << setw(2) << "|" << setw(2) << sizeTwo[0].c_str() << setw(2) << "|" << setw(2) << sizeTwo[2].c_str() << setw(2) << "|" << endl;
            output << "-----" << setw(1) << "+"  << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" <<endl;
            output << setw(4) << a1 << setw(2) << "|" << setw(2) << sizeTwo[1].c_str() << setw(2) << "|" << setw(2) << sizeTwo[3].c_str() << setw(2) << "|" << endl;
            output << "-----" << setw(1) << "+"  << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" <<endl;
            output <<endl;
            output <<endl;
            /*資訊*/
            output << "prime implcant" << endl;
            output << "essential prime implicant:" << endl;
            output << "F(A, B, C, D) = " << "\u03A3" << "m(";
            for(it_i=arr.begin();it_i != arr.end();++it_i) output << *it_i;
            output << ")" << endl;           
        }//End if
        else if (vsize[0]==4){
            for(auto &x : sizeFour){
                for (int i = 0; i < d; i++){
                    if (dsize[i]==x.first){
                        //x.second = "X";
                        sizeFour[x.first] = "X";
                    }//End if
                }//End for
                for (int i = 0; i < m; i++){
                    if (msize[i]==x.first){
                        sizeFour[x.first] = "1";
                    }//End if
                }//End for
                if(sizeFour[x.first]== " "){
                    sizeFour[x.first] = "0";
                }//End if
                if (sizeFour[x.first] == "1"){
                    arr.push_back(to_string(x.first));
                    arr.push_back(",");
                }
                //cout << x.first << ":" << x.second << " ";
            }//End For
            arr.pop_back();
            
            cout << endl;
            /*print to terminal*/
            /*圖表*/
            cout << "=========" << setw(1) << "Kmap" << setw(1) << "=========" <<endl;
            cout << setw(3) << "\\" << setw(1) << "AB"<< setw(1) << "|" << setw(16) << "|" <<endl;
            cout << "CD" << setw(2) << "\\" << setw(2) << "|" << setw(3) << a00 << setw(4) << a01 << setw(4) << a11 << setw(4) << a10 << "|" << endl;
            cout << "-----" << setw(1) << "+"  << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << endl;
            cout << setw(4) << a00 << setw(2) << "|" << setw(2) << sizeFour[0].c_str() << setw(2) << "|" << setw(2) << sizeFour[4].c_str() << setw(2) << "|" << setw(2) << sizeFour[12].c_str() << setw(2) << "|" << setw(2) << sizeFour[8].c_str() << setw(2) << "|" <<endl;
            cout << "-----" << setw(1) << "+"  << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << endl;
            cout << setw(4) << a01 << setw(2) << "|" << setw(2) << sizeFour[1].c_str() << setw(2) << "|" << setw(2) << sizeFour[5].c_str() << setw(2) << "|" << setw(2) << sizeFour[13].c_str() << setw(2) << "|" << setw(2) << sizeFour[9].c_str() << setw(2) << "|" <<endl;
            cout << "-----" << setw(1) << "+"  << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << endl;
            cout << setw(4) << a11 << setw(2) << "|" << setw(2) << sizeFour[3].c_str() << setw(2) << "|" << setw(2) << sizeFour[7].c_str() << setw(2) << "|" << setw(2) << sizeFour[15].c_str() << setw(2) << "|" << setw(2) << sizeFour[11].c_str() << setw(2) << "|" <<endl;
            cout << "-----" << setw(1) << "+"  << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << endl;
            cout << setw(4) << a10 << setw(2) << "|" << setw(2) << sizeFour[2].c_str() << setw(2) << "|" << setw(2) << sizeFour[6].c_str() << setw(2) << "|" << setw(2) << sizeFour[14].c_str() << setw(2) << "|" << setw(2) << sizeFour[10].c_str() << setw(2) << "|" <<endl;
            cout << "-----" << setw(1) << "+"  << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << endl;
            cout << endl;
            cout << endl;
            /*資訊*/
            cout << "prime implcant" << endl;
            cout << "essential prime implicant:" << endl;
            cout << "F(A, B, C, D) = " << "\u03A3" << "m(";
            for(it_i=arr.begin();it_i != arr.end();++it_i) cout << *it_i;
            cout << ")" << endl;
            /*export txt*/
            /*圖表*/
            output << "=========" << setw(1) << "Kmap" << setw(1) << "=========" <<endl;
            output << setw(3) << "\\" << setw(1) << "AB"<< setw(1) << "|" << setw(16) << "|" <<endl;
            output << "CD" << setw(2) << "\\" << setw(2) << "|" << setw(3) << a00 << setw(4) << a01 << setw(4) << a11 << setw(4) << a10 << "|" << endl;
            output << "-----" << setw(1) << "+"  << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << endl;
            output << setw(4) << a00 << setw(2) << "|" << setw(2) << sizeFour[0].c_str() << setw(2) << "|" << setw(2) << sizeFour[4].c_str() << setw(2) << "|" << setw(2) << sizeFour[12].c_str() << setw(2) << "|" << setw(2) << sizeFour[8].c_str() << setw(2) << "|" <<endl;
            output << "-----" << setw(1) << "+"  << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << endl;
            output << setw(4) << a01 << setw(2) << "|" << setw(2) << sizeFour[1].c_str() << setw(2) << "|" << setw(2) << sizeFour[5].c_str() << setw(2) << "|" << setw(2) << sizeFour[13].c_str() << setw(2) << "|" << setw(2) << sizeFour[9].c_str() << setw(2) << "|" <<endl;
            output << "-----" << setw(1) << "+"  << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << endl;
            output << setw(4) << a11 << setw(2) << "|" << setw(2) << sizeFour[3].c_str() << setw(2) << "|" << setw(2) << sizeFour[7].c_str() << setw(2) << "|" << setw(2) << sizeFour[15].c_str() << setw(2) << "|" << setw(2) << sizeFour[11].c_str() << setw(2) << "|" <<endl;
            output << "-----" << setw(1) << "+"  << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << endl;
            output << setw(4) << a10 << setw(2) << "|" << setw(2) << sizeFour[2].c_str() << setw(2) << "|" << setw(2) << sizeFour[6].c_str() << setw(2) << "|" << setw(2) << sizeFour[14].c_str() << setw(2) << "|" << setw(2) << sizeFour[10].c_str() << setw(2) << "|" <<endl;
            output << "-----" << setw(1) << "+"  << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << endl;
            output <<endl;
            output <<endl;
            /*資訊*/
            output << "prime implcant" << endl;
            output << "essential prime implicant:" << endl;
            output << "F(A, B, C, D) = " << "\u03A3" << "m(";
            for(it_i=arr.begin();it_i != arr.end();++it_i) output << *it_i;
            output << ")" << endl;
        }//End elif
        else if (vsize[0]==3){
            for(auto &x : sizeThree){
                for (int i = 0; i < d; i++){
                    if (dsize[i]==x.first){
                        //x.second = "X";
                        sizeThree[x.first] = "X";
                    }//End if
                }//End for
                for (int i = 0; i < m; i++){
                    if (msize[i]==x.first){
                        sizeThree[x.first] = "1";
                    }//End if
                }//End for
                if(sizeThree[x.first]== " "){
                    sizeThree[x.first] = "0";
                }//End if
                //cout << x.first << ":" << x.second << endl;
            }//End for
            /*print to terminal*/
            /*圖表*/
            cout << "=========" << setw(1) << "Kmap" << setw(1) << "=========" <<endl;
            cout << setw(3) << "\\" << setw(1) << "AB" << setw(1) << "|" << setw(16) << "|" <<endl;
            cout << setw(2) << "C" << setw(2) << "\\" << setw(2) << "|" << setw(3) << a00 << setw(4) << a01 << setw(4) << a11 << setw(4) << a10 << "|" << endl;
            cout << "-----" << setw(1) << "+"  << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << endl;
            cout << setw(4) << "0" << setw(2) << "|" << setw(2) << sizeThree[0].c_str() << setw(2) << "|" << setw(2) << sizeThree[2].c_str() << setw(2) << "|" << setw(2) << sizeThree[6].c_str() << setw(2) << "|" << setw(2) << sizeThree[4].c_str() << setw(2) << "|" <<endl;
            cout << "-----" << setw(1) << "+"  << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << endl;
            cout << setw(4) << "1" << setw(2) << "|" << setw(2) << sizeThree[1].c_str() << setw(2) << "|" << setw(2) << sizeThree[3].c_str() << setw(2) << "|" << setw(2) << sizeThree[7].c_str() << setw(2) << "|" << setw(2) << sizeThree[5].c_str() << setw(2) << "|" <<endl;
            cout << "-----" << setw(1) << "+"  << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << endl;
            cout << endl;
            cout << endl;
            /*資訊*/
            cout << "prime implcant" << endl;
            cout << "essential prime implicant:" << endl;
            cout << "F(A, B, C, D) = " << "\u03A3" << "m(";
            for(it_i=arr.begin();it_i != arr.end();++it_i) cout << *it_i;
            cout << ")" << endl;
            /*export txt*/
            /*圖表*/
            output << "=========" << setw(1) << "Kmap" << setw(1) << "=========" <<endl;
            output << setw(3) << "\\" << setw(1) << "AB" << setw(1) << "|" << setw(16) << "|" <<endl;
            output << setw(2) << "C" << setw(2) << "\\" << setw(2) << "|" << setw(3) << a00 << setw(4) << a01 << setw(4) << a11 << setw(4) << a10 << "|" << endl;
            output << "-----" << setw(1) << "+"  << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << endl;
            output << setw(4) << "0" << setw(2) << "|" << setw(2) << sizeThree[0].c_str() << setw(2) << "|" << setw(2) << sizeThree[2].c_str() << setw(2) << "|" << setw(2) << sizeThree[6].c_str() << setw(2) << "|" << setw(2) << sizeThree[4].c_str() << setw(2) << "|" <<endl;
            output << "-----" << setw(1) << "+"  << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << endl;
            output << setw(4) << "1" << setw(2) << "|" << setw(2) << sizeThree[1].c_str() << setw(2) << "|" << setw(2) << sizeThree[3].c_str() << setw(2) << "|" << setw(2) << sizeThree[7].c_str() << setw(2) << "|" << setw(2) << sizeThree[5].c_str() << setw(2) << "|" <<endl;
            output << "-----" << setw(1) << "+"  << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << setw(1) << "---" << setw(1) << "+" << endl;
            output << endl;
            output << endl;
            /*資訊*/
            output << "prime implcant" << endl;
            output << "essential prime implicant:" << endl;
            output << "F(A, B, C, D) = " << "\u03A3" << "m(";
            for(it_i=arr.begin();it_i != arr.end();++it_i) output << *it_i;
            output << ")" << endl;
            
        }//End Elif
    }//End if(output.is_open())



    //關閉檔案
    input.close();
    output.close();
    //fclose(fr);
    //fclose(fw);

    
    return 0;
}//End main()