#include <stdio.h>


int StrLen(char* str) { //длинна строки
  int len = 0;
  for (; str[len] != '\0'; len++);
  return len;
}


void ReplaceWord(char* line, char* sWord, char* fWord) {
  int lineLen = StrLen(line);   //длинна строки
  int sWordLen = StrLen(sWord); //длинна искомого слова
  int fWordLen = StrLen(fWord); //длинна вставляемого слова
  int isSame = 1;          //флажок на равенство искомого и вставляемого

  for (int i = 0, len = 0; ; i++, len++)
  {

    if (((line[i] != ' ') && (line[i] != '\0'))) {
      if (line[i] != sWord[len]) {// нахождение одинковых слов
        isSame = 0;
      }
    }

    else {
      if (isSame == 1) {
        if (sWordLen == fWordLen) // вставка если вставляемое равно искомому по длинне
        {
          for (int count = 1; len != 0; count++, len--)
          {
            line[i - count] = fWord[len - 1];
          }
        }

        else if (sWordLen > fWordLen) { // вставка если вставляемое меньше искомого по длинне
          
          for (int count = 0; line[i -len+ count] != '\0'; count++)
          {
            if (count < fWordLen ) //сначала вставляем вставляемое слово
            {
              line[i - len + count] = fWord[count];
            }

            else if (count >= fWordLen ) { // потом вставляем оставшийся текст после i
              line[i - len + count] = line[i - len + count + (sWordLen-fWordLen)];
            }
          }
          i -= (sWordLen - fWordLen);//строка уменьшилась так что счетчик i сдвигаеться влево
        }

        else if (sWordLen < fWordLen) { // вставка если вставляемое больше искомого по длинне
          for (int count = StrLen(line) + (fWordLen - sWordLen) - 1; count > i - sWordLen + fWordLen - 2; count--)//сдвигаем вправо строку после счетчика i
          {
            line[count] = line[count - (fWordLen - sWordLen)];
          }

          for (int count = i - sWordLen; count < i - sWordLen + fWordLen; count++) //вставляем слово на место прежнего
          {
            line[count] = fWord[count - i + sWordLen];
          }
          i += (fWordLen - sWordLen);//строка увеличилась так что счетчик i сдвигается вправо
        }
        
      }
      len = -1;
      isSame = 1;
    }
    
    if (line[i] == '\0') { //закончить если дошли до конца строки
    break;
    }
  }

  for (int n = 0; n < StrLen(line); n++) //вывод строки
  {
    printf("%c", line[n]);
  }

}

int main() {
  char str[100] = "qwedd ok qwedd asdqwe qwedd ok qwedd";
  char word[10] = "qwedd";
  char word1[10] = "wwwww";

  ReplaceWord(str, word, word1);

}
