void readAhead(size_t amount)
{
    size_t remaining=stdinDataEnd-stdinPos;
    if(remaining<amount) {
       memmove(stdinBuffer, stdinPos, remaining);
       size_t sz=fread(stdinBuffer+remaining, 1, sizeof(stdinBuffer)-remaining, stdin);
       stdinPos=stdinBuffer;
       stdinDataEnd=stdinBuffer+remaining+sz;
       if(stdinDataEnd!=stdinBuffer+sizeof(stdinBuffer))
         *stdinDataEnd = 0;
    }
}

template<class T> void read(T &X)
{
    readAhead(16);
    X=0;
    while(*stdinPos>47 && *stdinPos<58) {
       X=10*X+*stdinPos-48;
       ++stdinPos;
    }
    ++stdinPos;
}