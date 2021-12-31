#include<bits/stdc++.h>
using namespace std;

int findLRU(vector<int> time, int no_of_frames){
    int minimum = time[0], position = 0;
    for(int i=1; i<no_of_frames; i++){
        if(time[i] < minimum){
            minimum = time[i];
            position = i;
        }
    }
    return position;
}

int main(){
    int no_of_frames, no_of_pages, count=0, flag1, flag2, position, page_faults=0;
    vector<int> frames(no_of_frames, -1), pages(no_of_pages), time(no_of_frames);
    cout << "Enter number of frames: ";
    cin >> no_of_frames;
    cout << "\nEnter number of pages: ";
    cin >> no_of_pages;
    cout << "\nEnter reference string: ";
    for(int i=0; i<no_of_pages; i++){
        cin >> pages[i];
    }
    for(int i=0; i<no_of_pages; i++){
        flag1 = flag2 = 0;
        for(int j=0; j<no_of_frames; j++){
            if(frames[j] == pages[i]){
                count++;
                time[j] = count;
                flag1 = flag2 = 1;
                break;
            }
        }
        if(flag1 == 0){
            for(int j=0; j<no_of_frames; j++){
                if(frames[j] == -1){
                    count++;
                    page_faults++;
                    frames[j] = pages[i];
                    time[j] = count;
                    flag2 = 1;
                    break;
                }
            }
        }
        if(flag2 == 0){
            position = findLRU(time, no_of_frames);
            count++;
            page_faults++;
            frames[position] = pages[i];
            time[position] = count;
        }
        cout << endl;
        for(int j=0; j<no_of_frames; j++){
            cout << frames[j] << " ";
        }
    }
    cout << "\n\nPage faults = " << page_faults << endl;
    cout << "Hits = " << no_of_pages-page_faults << endl;
    cout << "Hit ratio = " << (no_of_pages-page_faults)*100/no_of_pages << "%" << endl;
    return 0;
}