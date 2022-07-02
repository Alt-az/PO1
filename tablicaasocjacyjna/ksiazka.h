#ifndef __KSIAZKA_H__
#define __KSIAZKA_H__

#include <string.h>

class ksiazka {
	public:
	const char* autor;
	const char* status;
	unsigned int liczba_stron;
	ksiazka(const char* Autor, const char* Status, int Liczba_stron) {
		autor = Autor;
		status = Status;
		liczba_stron = Liczba_stron;
	}

	ksiazka(const ksiazka& s) {
		autor = s.autor;
		status = s.status;
		liczba_stron = s.liczba_stron;
	}
	
};
	ostream& operator<<(ostream& o, const ksiazka& t) {
			o << "  autor:" << t.autor;
			o << "  status:" << t.status;
			o << "  liczba stron:" << t.liczba_stron;
		return o;
	}
#endif /* __KSIAZKA_H__ */
