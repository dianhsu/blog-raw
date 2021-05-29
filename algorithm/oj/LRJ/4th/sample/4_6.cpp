#include <bits/stdc++.h>
#define EPS 1e-5
using namespace std;
struct Student{
    string sid;
    int cid;
    string name;
    int score[4];
};

vector<Student> vec;
void print_menu();
void f_add();
void f_remove();
void f_query();
void f_ranking();
void f_statistics();
int main(){
    cout.setf(ios::fixed);
    cout.precision(2);
    int cmd;
    while(1){
        print_menu();
        cin >> cmd;
        if(cmd == 0) break;
        else if(cmd == 1) f_add();
        else if(cmd == 2) f_remove();
        else if(cmd == 3) f_query();
        else if(cmd == 4) f_ranking();
        else if(cmd == 5) f_statistics();
    }
    return 0;
}
void f_statistics(){
    cout << "Please enter class ID, 0 for the whole statistics." << endl;
    int cid;
    cin >> cid;
    int sum_score[4];
    int person = 0;
    int passed[5];
    int subject_pass[4], subject_fail[4];
    memset(sum_score, 0, sizeof sum_score);
    memset(passed, 0, sizeof passed);
    memset(subject_pass, 0, sizeof subject_pass);
    memset(subject_fail, 0, sizeof subject_fail);
    string subjects[4] = {"Chinese", "Mathematics", "English", "Programming"};
    for(auto item: vec){
        if(cid == 0 or cid == item.cid){
            int tmp = 0;
            ++person;
            for(int i = 0; i < 4; ++i){
                sum_score[i] += item.score[i];
                if(item.score[i] >= 60){
                    tmp++;
                    subject_pass[i]++;
                }else{
                    subject_fail[i]++;
                }
            }
            passed[tmp]++;
        }
    }
    for(int i = 0; i < 4; ++i){
        cout << subjects[i] << endl;
        cout << "Average Score: " << sum_score[i]*1.0/person+EPS << endl;
        cout << "Number of passed students: " << subject_pass[i] << endl;
        cout << "Number of failed students: " << subject_fail[i] << endl;
        cout << endl;
    }
    cout << "Overall:" << endl;
    cout << "Number of students who passed all subjects: " << passed[4] << endl;
    cout << "Number of students who passed 3 or more subjects: " << passed[3]+passed[4] << endl;
    cout << "Number of students who passed 2 or more subjects: " << passed[2]+passed[3]+passed[4] << endl;
    cout << "Number of students who passed 1 or more subjects: " << passed[1]+passed[2]+passed[3]+passed[4] << endl;
    cout << "Number of students who failed all subjects: " << passed[0] << endl;
    cout << endl;
}

void f_ranking(){
    cout << "Showing the ranklist hurts students' self-esteem. Don't do that." << endl;
}
void f_query(){
    cout << "Please enter SID or name. Enter 0 to finish." << endl;
    vector<int> rank;
    string key;
    while(cin >> key and key != "0"){
        rank.clear();
        for(auto item: vec){
            rank.push_back(item.score[0]+item.score[1]+item.score[2]+item.score[3]);
        }
        sort(rank.begin(), rank.end());
        for(auto item: vec){
            if(item.sid == key or item.name == key){
                int sum = item.score[0] + item.score[1] + item.score[2] + item.score[3];
                for(auto ptr = rank.rbegin(); ptr != rank.rend(); ++ptr){
                    if(*ptr == sum){
                        cout << (ptr-rank.rbegin())+1;
                        break;
                    }
                }
                cout << " " << item.sid << " " << item.cid << " " << item.name
                    << " " << item.score[0] << " " << item.score[1] 
                    << " " << item.score[2] << " " << item.score[3]
                    << " " << sum << " " << sum*0.25 << endl;
            }
        }
        cout << "Please enter SID or name. Enter 0 to finish." << endl;
    }
}

void f_remove(){
    cout << "Please enter SID or name. Enter 0 to finish." << endl;
    string key;
    while(cin >> key and key != "0"){
        vector<Student> tmp = vec;
        vec.clear();
        int match = 0;
        for(auto item: tmp){
            if(item.sid == key or item.name == key){
                ++match;
            }else{
                vec.push_back(item);
            }
        }
        cout << match << " student(s) removed." << endl;
        cout << "Please enter SID or name. Enter 0 to finish." << endl;
    }
}
void f_add(){
    Student stu;
    cout << "Please enter the SID, CID, name and four scores. Enter 0 to finish." << endl;
    while(cin >> stu.sid and stu.sid != "0"){
        cin >> stu.cid >> stu.name 
            >> stu.score[0] >> stu.score[1] 
            >> stu.score[2] >> stu.score[3];
        bool duplicated = false;
        for(auto item: vec){
            if(item.sid == stu.sid){
                duplicated = true;
                break;
            }
        }
        if(duplicated){
            cout << "Duplicated SID." << endl;
        }else{
            vec.push_back(stu);
        }
        cout << "Please enter the SID, CID, name and four scores. Enter 0 to finish." << endl;
    }
}
void print_menu(){
    cout << "Welcome to Student Performance Management System (SPMS).\n"
        << "\n"
        << "1 - Add\n"
        << "2 - Remove\n"
        << "3 - Query\n"
        << "4 - Show ranking\n"
        << "5 - Show Statistics\n"
        << "0 - Exit\n"
        << endl;
}
