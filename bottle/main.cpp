#include <iostream>

using namespace std;

class CBottle {

    private:
            int mCapacity;
            int mLevel;

    public:
        int getCapacity(){
            return mCapacity;
        }

        int getLevel(){
            return mLevel;
        }

        virtual void Fill (int amount){
            if (amount <= 0){
                cout<<"Blad, nie da sie napelnic butelki"<<endl;
            } else if (amount + mLevel >= mCapacity) {
                mLevel = mCapacity;
                cout<<"Butelka ma teraz: "<<mLevel<<" ml"<<endl;
            } else if( amount + mLevel < mCapacity) {
                mLevel = mLevel + amount;
                cout<<"Butelka ma teraz: "<<mLevel<<" ml"<<endl;
            } else {
                cout<<"Blad";
            }
        }

        virtual void Tip (int amount) {
            if (amount >= mLevel) {
                mLevel = 0;
                cout<<"Butelka jest pusta :("<<endl;
            } else if(amount < mLevel) {
                mLevel = mLevel - amount;
            }

        }

        CBottle() {
            mCapacity = 550;
            mLevel = 100;
        }
};



class CCap {
    private:
        bool Screwed;

    public:
        int getScrewed() {
            return Screwed;
        }

        void Screw() {
            Screwed = true;
            cout<<"Zakretka jest zakrecona"<<endl;
        }

        void Unscrew() {
            Screwed = false;
            cout<<"Zakretka jest odkrecona"<<endl;

        }

        CCap() {
            Screwed = true;
        }
};

class CCapBottle: public CBottle {
    public:
        CCap Cap;

        void Fill(int amonut) {
            if(Cap.getScrewed() == false)
                CBottle::Fill(amonut);
            else
                cout<<"Butelka zakrecona, nie mozna dolac do niej"<<endl;
        }

        void Tip(int amount) {
            if(Cap.getScrewed() == false)
                CBottle::Tip(amount);
            else
                cout<<"Butelka zakrecona, nie mozna z niej wylac"<<endl;
        }
    };

    int main() {
        CBottle myBottle;
        CCap myCap;
        cout<<"Poziom w butelce to "<<myBottle.getLevel()<<" ml"<<endl;
        cout<<"Pojemnosc butelki to "<<myBottle.getCapacity()<<" ml"<<endl;

        myBottle.Fill(100);
        myBottle.Tip(50);

        myCap.getScrewed();
        myCap.Screw();
        myCap.Unscrew();

        return 0;
}
