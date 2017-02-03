#include <cstdio>
#include <bitset>
using namespace std;



int main() {
freopen("test.txt","r",stdin);
freopen("answer.txt","w",stdout);
	int one, rep, s, e, itv;
	bool conflict;
	while (scanf("%d %d", &one, &rep), one || rep) {
		conflict = false;
		bitset<1000005> bs;

		for (int i = 0; i < one; i++) {
			scanf("%d %d", &s, &e);
			if (!conflict) {
				for (int j = s + 1; j <= e; j++) {
					if (bs.test(j)) {
						conflict = true;
						break;
					}
					bs.set(j);
				}
			}
		}

		for (int i = 0; i < rep; i++) {
			scanf("%d %d %d", &s, &e, &itv);
			if (!conflict) {
				while (true) {
					for (int j = s + 1; j <= e; j++) {
						if (bs.test(j)) {
							conflict = true;
							break;
						}
						bs.set(j);
					}
					s += itv;
					e += itv;
					if (s > 1000000 && e > 1000000)
						break;
					else if (e > 1000000)
						e = 1000000;
				}
			}
		}

		if (conflict)
			printf("CONFLICT\n");
		else
			printf("NO CONFLICT\n");

	}

	return 0;
}
