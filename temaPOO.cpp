#include <iostream>
#include <cctype>
using namespace std;


class randul {
public:
    float carno, pret;
    randul(int ida, float carnoa, string masinaA, float preta) {
        id = ida;
        carno = carnoa;
        masina = masinaA;
        pret = preta;
    }

    void afis() {
        if (carno == 0)
            cout << "Nu s-a vandut nici o masina din randul " << id << endl;
        else
            cout << "De pe randul " << id << " s-au vandut " << carno << " masini " << masina << "." << endl;
    }

    float profit() {
        return carno * pret;
    }

    ~randul() {
        cout << "Randul " << id << " a fost epuizat" << endl;
    }
private:
    string masina;
    int id;
};

int main()
{
    string aux[4];
    float v[4], p[4];
    for (int i = 1; i <= 3; i++)
    {
        cout << "Ce tip de masini sunt pe randul " << i << "?" << endl;
        cin >> aux[i]; cout << endl;
    errpret:
        cout << "Care este pretul mediu al masinilor?" << endl;
        cin >> p[i]; cout << endl;
        if (p[i] <= 0) {
            cout << "Pret invalid." << endl << endl;
            goto errpret;
        }
    errvand:
        cout << "Cate masini s-au vandut de acest tip?" << endl;
        cin >> v[i]; cout << endl;
        if (v[i] < 0) {
            cout << "Numar invalid." << endl << endl;
            goto errvand;
        }
    }
    
    randul randul1(1, v[1], aux[1], p[1]), randul2(2, v[2], aux[2], p[2]), randul3(3, v[3], aux[3], p[3]);
    randul1.afis();
    randul2.afis();
    randul3.afis();
    cout << "In total s-au vandut " << randul1.carno + randul2.carno + randul3.carno << " masini astazi, in valoare de ";
    cout << randul1.profit() + randul2.profit() + randul3.profit() << " de lei sau "<< (randul1.profit() + randul2.profit() + randul3.profit())/5<<" de euro." << endl;
    return 0;
}