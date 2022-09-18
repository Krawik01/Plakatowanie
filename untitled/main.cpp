#include <iostream>
#include <vector>

int main() {

    std::ios_base::sync_with_stdio(false);

    long amount = 0;
    int posters = 0;

    std::vector<long> list;
    std::vector<long> listTmp;


  //  scanf("%d\n",&amount);
    std::cin >> amount;
   // std::cout << "the number of buildings is: " << amount << "\n";

    if ((amount<1)||(amount>250000)){
        exit(0);
    }long w; long h;


    for (int i = 0; i < amount; ++i) {
      //std::cout << " please state the width and height of building number: " << i << "\n";
        std::cin >> w >> h;
       // scanf("%d %d\n",&w,&h);
        if((((w)<1)||(w)>1000000000)||((h<1)||(h>1000000000))){
            exit(0);
        }
        list.push_back(h);
    }


    list.push_back(0);
    list.push_back(0);
    listTmp.push_back(list.at(0));

    long min = list.at(0);

    //we find the smallest height
    for (int i = 0; i < list.size(); ++i) {
        if((list.at(i) < min) && (list.at(i) != 0)){
            min=list.at(i);
        }
    }
    //we check how many times the lowest height occurs
    int minCounter = 0;
    for (int i = 0; i < list.size(); ++i) {
        if(list.at(i) == min){
            minCounter++;
        }
    }

    if(minCounter > 1){
        posters = posters - (minCounter - 1);
    }
    int checkPoint = 0;

    for (int i = 0; i < list.size() - 2; ++i) {

        if (checkPoint > 0) {
            listTmp.push_back(list.at(i));
            checkPoint = 0;
        }
        if ((list.at(i) < list.at(i + 1))) {

            listTmp.push_back(list.at(i + 1));

        } else {
            int x = 0;

            /*
             * check how many times the same height occurs on the currently examined cutoff in the temporary list
             */
            for (int k = 0; k < listTmp.size(); ++k) {
                for (int l = 0; l < listTmp.size(); ++l) {
                    if ((listTmp.at(k) == listTmp.at(l) && k != l)) {
                        listTmp.at(l) = 9999 - (k + x);
                        x++;
                    }
                }
            }
            posters = posters + (listTmp.size() - x);

            listTmp.clear();

            checkPoint = 1;
        }

    }
    printf("%d\n",posters);
    return 0;
}
