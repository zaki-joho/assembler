#include "bits/stdc++.h"

using namespace std;
int line = 0;

// r[Rs] を 000 ~ 111 に変換 
string s_to_b(string s){
    if(s[2] == '0') return "000";
    else if(s[2] == '1') return "001";
    else if(s[2] == '2') return "010";
    else if(s[2] == '3') return "011";
    else if(s[2] == '4') return "100";
    else if(s[2] == '5') return "101";
    else if(s[2] == '6') return "110";
    else if(s[2] == '7') return "111";
    else{
        cout << "parsing failed" << "(in line: " << line << ")" <<endl;
        return 0;
    }
}

int main(){
    string inst;
    while(cin >> inst){
        if(inst[0] == '#') continue;
        line++;
        string sub2="**", sub3="***";
        if(inst.length() >= 2) sub2 = inst.substr(0,2);
        else if(inst.length() == 3) sub3 = inst.substr(0,3);
        else{
            cout << "parsing failed" << "(in line: " << line << ")" <<endl;
            return 0;
        }

        string res = "";
        if(sub3 == "ADD" || sub3 == "SUB" || sub3 == "AND" || sub2 == "OR" ||
           sub3 == "XOR" || sub3 == "CMP" || sub3 == "MOV"){
            res += "11";
            string rd,rs;cin>>rd>>rs;

            res += s_to_b(rs);
            res += s_to_b(rd);

            if(sub3 == "ADD") res += "0000";
            else if(sub3 == "SUB") res += "0001";
            else if(sub3 == "AND") res += "0010";
            else if(sub2 == "OR") res += "0011";
            else if(sub3 == "XOR") res += "0100";
            else if(sub3 == "CMP") res += "0101";
            else if(sub3 == "MOV") res += "0110";
            else{
                cout << "parsing failed" << "(in line: " << line << ")" << endl;
                return 0;
            }

            res += "0000";
        }
        else if(sub3 == "SLL" || sub3 == "SLR" || sub3 == "SRL"||sub3 == "SRA"){
            res += "11";
            string rd,d;cin>>rd>>d;

            res += "000";
            res += s_to_b(rd);

            if(sub3 == "SLL") res += "1000";
            else if(sub3 == "SLR" ) res += "1001";
            else if(sub3 == "SRL") res += "1010";
            else if(sub3 == "SRA") res += "1011";
            else{
                cout << "parsing failed" << "(in line: " << line << ")" << endl;
                return 0;
            }

            res += d;
        }
        else if(sub2 == "IN"){
            res += "11";
            string rd,d;cin>>rd>>d;

            res += "000";
            res += s_to_b(rd);
            res += "1100";
            res += d;
        }
        else if(sub3 == "OUT"){
            res += "11";
            string rs;cin>>rs;

            res += s_to_b(rs);
            res += s_to_b(rs);
            res += "1101";
            res += "0000";
        }
        else if(sub3 == "HLT"){
            res += "11";
            res += "000";
            res += "000";
            res += "1111";
            res += "0000";
        }
        else if(sub2 == "LD"){
            string ra,rb,d;cin>>ra>>rb>>d;
            
            res += "00";
            res += s_to_b(ra);
            res += s_to_b(rb);
            res += d;
        }
        else if(sub2 == "ST"){
            string ra,rb,d;cin>>ra>>rb>>d;
            
            res += "01";
            res += s_to_b(ra);
            res += s_to_b(rb);
            res += d;
        }
        else if(sub2 == "LI"){
            string rb,d;cin>>rb>>d;

            res += "10";
            res += "000";
            res += s_to_b(rb);
            res += d;
        }
        else if(sub2 == "BR"){
            string rb,d;cin>>rb>>d;

            res += "10";
            res += "100";
            res += s_to_b(rb);
            res += d;
        }
        else if(sub2 == "BE" || sub3 =="BLT" || sub3=="BLE"||sub3=="BNE"){
            string d;cin>>d;

            res+="10";
            res+="111";

            if(sub2 == "BE") res+="000";
            else if(sub3 =="BLT") res+="001";
            else if(sub3 =="BLE") res+="010";
            else if(sub3 =="BNE") res+="011";
            else{
                cout << "parsing failed" << "(in line: " << line << ")" << endl;
                return 0;
            }

            res+=d;
        }
        else{
            cout << "parsing failed" << "(in line: " << line << ")" << endl;
            return 0;
        }
        cout<<res<<endl;
    }
}