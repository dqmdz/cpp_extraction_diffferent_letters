#include "../include/extraction.h"

bool contains(char *start, const char *end, char element)
{
    while (start <= end)
        if (*(start++) == element)
            return true;
    return false;
}

string extraction(const char *phrase)
{
    // case: without phrase
    if (*phrase == 0)
        return "";
    // case: one letter
    if (*(phrase + 1) == 0)
        return phrase;
    // else
    char *start = (char *)phrase;
    char *end_phrase = start + strlen(phrase) - 1;
    // droping same letter at the beginning
    while (*start == *(start + 1))
        start++;
    if (start == end_phrase)
        return string(start, start + 1);
    
    char *end = start;
    // droping same letter at the end
    while (*end_phrase == *(end_phrase - 1))
        end_phrase--;
    string result = "";
    while (end <= end_phrase)
    {
        string temp = string(start, end + 1);
        if (temp.length() > result.length())
            result = temp;
        if (*(end + 1))
            if (contains(start, end, *(end + 1)))
                if (end_phrase - end > end - start)
                    if (*(end + 1) == *end)
                        start = ++end;
                    else
                        start += 1;
                else
                    return result;
        end++;
    }
    return result;
}
