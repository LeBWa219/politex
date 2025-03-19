#include <stdio.h>


int StrLen(char* str) { //������ ������
  int len = 0;
  for (; str[len] != '\0'; len++);
  return len;
}


void ReplaceWord(char* line, char* sWord, char* fWord) {
  int lineLen = StrLen(line);   //������ ������
  int sWordLen = StrLen(sWord); //������ �������� �����
  int fWordLen = StrLen(fWord); //������ ������������ �����
  int isSame = 1;          //������ �� ��������� �������� � ������������

  for (int i = 0, len = 0; ; i++, len++)
  {

    if (((line[i] != ' ') && (line[i] != '\0'))) {
      if (line[i] != sWord[len]) {// ���������� ��������� ����
        isSame = 0;
      }
    }

    else {
      if (isSame == 1) {
        if (sWordLen == fWordLen) // ������� ���� ����������� ����� �������� �� ������
        {
          for (int count = 1; len != 0; count++, len--)
          {
            line[i - count] = fWord[len - 1];
          }
        }

        else if (sWordLen > fWordLen) { // ������� ���� ����������� ������ �������� �� ������
          
          for (int count = 0; line[i -len+ count] != '\0'; count++)
          {
            if (count < fWordLen ) //������� ��������� ����������� �����
            {
              line[i - len + count] = fWord[count];
            }

            else if (count >= fWordLen ) { // ����� ��������� ���������� ����� ����� i
              line[i - len + count] = line[i - len + count + (sWordLen-fWordLen)];
            }
          }
          i -= (sWordLen - fWordLen);//������ ����������� ��� ��� ������� i ����������� �����
        }

        else if (sWordLen < fWordLen) { // ������� ���� ����������� ������ �������� �� ������
          for (int count = StrLen(line) + (fWordLen - sWordLen) - 1; count > i - sWordLen + fWordLen - 2; count--)//�������� ������ ������ ����� �������� i
          {
            line[count] = line[count - (fWordLen - sWordLen)];
          }

          for (int count = i - sWordLen; count < i - sWordLen + fWordLen; count++) //��������� ����� �� ����� ��������
          {
            line[count] = fWord[count - i + sWordLen];
          }
          i += (fWordLen - sWordLen);//������ ����������� ��� ��� ������� i ���������� ������
        }
        
      }
      len = -1;
      isSame = 1;
    }
    
    if (line[i] == '\0') { //��������� ���� ����� �� ����� ������
    break;
    }
  }

  for (int n = 0; n < StrLen(line); n++) //����� ������
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
