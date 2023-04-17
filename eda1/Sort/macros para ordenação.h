typedef int Item; // define o tipo 'Item' como inteiro

#define key(a) a // retorna a chave do Item 'a'
#define less(a, b) (key(a) < key(b)) // retorna verdadeiro se a chave de 'a' for menor que a chave de 'b', senão retorna falso
#define exch(a, b) {Item t=a;a=b;b=t;} // faz a troca entre os Itens 'a' e 'b'
#define cmpexch(a, b) {if(less(b, a))exch(a, b)} // se a chave de 'b' for menor que a chave de 'a', faz a troca entre os Itens 'a' e 'b'
