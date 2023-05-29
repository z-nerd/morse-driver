#include <morse.h>


void struwr(char s[]) {
	int i = 0;

	for (i = 0; s[i] != '\0'; i++) 
		if(s[i] >= 'a' && s[i] <= 'z') 
			s[i] = s[i] - (char)32;
}

void enToMorse(
	char msg[], 
	char code[], 
	char const *splitter,
	char const *space
	) {
	char *s = msg;

 	struwr(s);

	for(int i = 0; i < strlen(s); i++) { 
		switch(s[i]) {
			case ' ':	strcat(code, space); break;
			case '0':	strcat(code, "-----"); strcat(code, splitter); break;
			case '1':	strcat(code, ".----"); strcat(code, splitter); break;
			case '2':	strcat(code, "..---"); strcat(code, splitter); break;
			case '3':	strcat(code, "...--"); strcat(code, splitter); break;
			case '4':	strcat(code, "....-"); strcat(code, splitter); break;
			case '5':	strcat(code, "....."); strcat(code, splitter); break;
			case '6':	strcat(code, "-...."); strcat(code, splitter); break;
			case '7':	strcat(code, "--..."); strcat(code, splitter); break;
			case '8':	strcat(code, "---.."); strcat(code, splitter); break;
			case '9':	strcat(code, "----."); strcat(code, splitter); break;

			case 'A':	strcat(code, ".-"); strcat(code, splitter); break;
			case 'B':	strcat(code, "-..."); strcat(code, splitter); break;
			case 'C':	strcat(code, "-.-."); strcat(code, splitter); break;
			case 'D':	strcat(code, "-.."); strcat(code, splitter); break;
			case 'E':	strcat(code, "."); strcat(code, splitter); break;
			case 'F':	strcat(code, "..-."); strcat(code, splitter); break;
			case 'G':	strcat(code, "--."); strcat(code, splitter); break;
			case 'H':	strcat(code, "...."); strcat(code, splitter); break;
			case 'I':	strcat(code, ".."); strcat(code, splitter); break;
			case 'J':	strcat(code, ".---"); strcat(code, splitter); break;
			case 'K':	strcat(code, "-.-"); strcat(code, splitter); break;
			case 'L':	strcat(code, ".-.."); strcat(code, splitter); break;
			case 'M':	strcat(code, "--"); strcat(code, splitter); break;
			case 'N':	strcat(code, "-."); strcat(code, splitter); break;
			case 'O':	strcat(code, "---"); strcat(code, splitter); break;
			case 'P':	strcat(code, ".--."); strcat(code, splitter); break;
			case 'Q':	strcat(code, "--.-"); strcat(code, splitter); break;
			case 'R':	strcat(code, ".-."); strcat(code, splitter); break;
			case 'S':	strcat(code, "..."); strcat(code, splitter); break;
			case 'T':	strcat(code, "-"); strcat(code, splitter); break;
			case 'U':	strcat(code, "..-"); strcat(code, splitter); break;
			case 'V':	strcat(code, "...-"); strcat(code, splitter); break;
			case 'W':	strcat(code, ".--"); strcat(code, splitter); break;
			case 'X':	strcat(code, "-..-"); strcat(code, splitter); break;
			case 'Y':	strcat(code, "-.--"); strcat(code, splitter); break;
			case 'Z':	strcat(code, "--.."); strcat(code, splitter); break;

			case '.':	strcat(code, ".-.-.-"); strcat(code, splitter); break;
			case ',':	strcat(code, "--..--"); strcat(code, splitter); break;
			case '\'':	strcat(code, ".----."); strcat(code, splitter); break;
			case '?':	strcat(code, "..--.."); strcat(code, splitter); break;
			case '!':	strcat(code, "-.-.--"); strcat(code, splitter); break;
			case '/':	strcat(code, "-..-."); strcat(code, splitter); break;
			case '(':	strcat(code, "-.--. "); strcat(code, splitter); break;
			case ')':	strcat(code, "-.--.-"); strcat(code, splitter); break;
			case '&':	strcat(code, ".-..."); strcat(code, splitter); break;
			case ':':	strcat(code, "---..."); strcat(code, splitter); break;
			case ';':	strcat(code, "-.-.-."); strcat(code, splitter); break;
			case '=':	strcat(code, "-...-"); strcat(code, splitter); break;
			case '+':	strcat(code, ".-.-."); strcat(code, splitter); break;
			case '-':	strcat(code, "-....-"); strcat(code, splitter); break;
			case '_':	strcat(code, "..--.-"); strcat(code, splitter); break;
			case '"':	strcat(code, ".-..-."); strcat(code, splitter); break;
			case '$':	strcat(code, "...-..-"); strcat(code, splitter); break;
			case '@':	strcat(code, ".--.-."); strcat(code, splitter); break;
		}
	}
}

// void faToMorse(
// 	char msg[], 
// 	char code[], 
// 	char const *splitter,
// 	char const *space
// 	) {
// 	char *s = msg;

// 	for(int i = 0; i < strlen(s); i++) { 
// 		switch(s[i]) {
// 			case ' ':	strcat(code, space); break;
// 			case '۰':	strcat(code, "-----"); strcat(code, splitter); break;
// 			case '۱':	strcat(code, ".----"); strcat(code, splitter); break;
// 			case '۲':	strcat(code, "..---"); strcat(code, splitter); break;
// 			case '۳':	strcat(code, "...--"); strcat(code, splitter); break;
// 			case '۴':	strcat(code, "....-"); strcat(code, splitter); break;
// 			case '۵':	strcat(code, "....."); strcat(code, splitter); break;
// 			case '۶':	strcat(code, "-...."); strcat(code, splitter); break;
// 			case '۷':	strcat(code, "--..."); strcat(code, splitter); break;
// 			case '۸':	strcat(code, "---.."); strcat(code, splitter); break;
// 			case '۹':	strcat(code, "----."); strcat(code, splitter); break;
			
// 			case 'ا':	strcat(code, ".-"); strcat(code, splitter); break;
// 			case 'ب':	strcat(code, "-..."); strcat(code, splitter); break;
// 			case 'پ':	strcat(code, ".--."); strcat(code, splitter); break;
// 			case 'ت':	strcat(code, "-"); strcat(code, splitter); break;
// 			case 'ث':	strcat(code, "-.-."); strcat(code, splitter); break;
// 			case 'ج':	strcat(code, ".---"); strcat(code, splitter); break;
// 			case 'چ':	strcat(code, "---."); strcat(code, splitter); break;
// 			case 'ح':	strcat(code, "...."); strcat(code, splitter); break;
// 			case 'خ':	strcat(code, "-..-"); strcat(code, splitter); break;
// 			case 'د':	strcat(code, "-.."); strcat(code, splitter); break;
// 			case 'ذ':	strcat(code, "...-"); strcat(code, splitter); break;
// 			case 'ر':	strcat(code, ".-."); strcat(code, splitter); break;
// 			case 'ز':	strcat(code, "--.."); strcat(code, splitter); break;
// 			case 'ژ':	strcat(code, "--."); strcat(code, splitter); break;
// 			case 'س':	strcat(code, "..."); strcat(code, splitter); break;
// 			case 'ش':	strcat(code, "----"); strcat(code, splitter); break;
// 			case 'ص':	strcat(code, ".-.-"); strcat(code, splitter); break;
// 			case 'ض':	strcat(code, "..-.."); strcat(code, splitter); break;
// 			case 'ط':	strcat(code, "..-"); strcat(code, splitter); break;
// 			case 'ظ':	strcat(code, "-.--"); strcat(code, splitter); break;
// 			case 'ع':	strcat(code, "---"); strcat(code, splitter); break;
// 			case 'غ':	strcat(code, "..--"); strcat(code, splitter); break;
// 			case 'ف':	strcat(code, "..-."); strcat(code, splitter); break;
// 			case 'ق':	strcat(code, "---..."); strcat(code, splitter); break;
// 			case 'ک':	strcat(code, "-.-"); strcat(code, splitter); break;
// 			case 'گ':	strcat(code, "--.-"); strcat(code, splitter); break;
// 			case 'ل':	strcat(code, ".-.."); strcat(code, splitter); break;
// 			case 'م':	strcat(code, "--"); strcat(code, splitter); break;
// 			case 'ن':	strcat(code, "-."); strcat(code, splitter); break;
// 			case 'و':	strcat(code, ".--"); strcat(code, splitter); break;
// 			case 'ه':	strcat(code, "."); strcat(code, splitter); break;
// 			case 'ی':	strcat(code, ".."); strcat(code, splitter); break;
			
// 			case '.':	strcat(code, "......"); strcat(code, splitter); break;
// 			case '،':	strcat(code, ".-.-.-"); strcat(code, splitter); break;
// 			case '؛':	strcat(code, "-.-.-."); strcat(code, splitter); break;
// 			case ':':	strcat(code, "---..."); strcat(code, splitter); break;
// 			case '؟':	strcat(code, "..--.."); strcat(code, splitter); break;
// 			case '!':	strcat(code, "--..--"); strcat(code, splitter); break;
// 			case '-':	strcat(code, "-....-"); strcat(code, splitter); break;
// 			case '/':	strcat(code, "------"); strcat(code, splitter); break;
// 			case 'ـ':	strcat(code, "..--.-"); strcat(code, splitter); break;
// 		}
// 	}
// }