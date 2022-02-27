c A Fortran subroutine (from R.C. Singleton, Algorithm 347, An efficient
c algorithm for sorting with minimal storage, Comm. ACM 12, 3 (March 1969),
c p. 186, with some added comments):
      subroutine sort(a,ii,jj)
c variation on quicksort sorts array a into increasing order from a(ii) to a(jj)
c arrays iu(k) and il(k) permit sorting up to 2**(k+1)-1 elements
      dimension a(1),iu(16),il(16)
      integer a,t,tt
      m=1
      i=ii
      j=jj
5     if (i .ge. j) goto 70
c set t to median of a(i), a((i+j)/2), a(j)
10    k=i
      ij=(j+i)/2
      t=a(ij)
      if (a(1) .le. t) goto 20
      a(ij)=a(i)
      a(i)=t
      t=a(ij)
20    l=j
      if (a(j) .ge. t) goto 40
      a(ij)=a(j)
      a(j)=t
      t=a(ij)
      if (a(i) .le. t) goto 40
      a(ij)=a(i)
      a(i)=t
      t=a(ij)
      goto 40
30    a(l)=a(k)
      a(k)=tt
c use t to split segment
40    l=l-1
      if (a(l) .gt. t) goto 40
      tt=a(l)
50    k=k+1
      if (a(k) .lt. t) goto 50
      if (k .le. l) goto 30
c stack one segment to be sorted later
      if (l-i .le. j-k) goto 60
      il(m)=i
      iu(m)=l
      i=k
      m=m + 1
      goto 80
60    il(m)=k
      iu(m)=j
      j=l
      m=m+1
      goto 80
c find next segment to be sorted
70    m=m-1
      if (m .eq. 0) return
      i=il(m)
      j=iu(m)
80    if (j - i .ge. 11) goto 10
c sort small segments
      if (i .eq. ii) goto 5
      i=i-1
90    i=i+1
      if (i .eq. j) goto 70
      t=a(i+1)
      if (a(i) .le. t) goto 90
      k=i
100   a(k+1)=a(k)
      k=k-1
      if (t .lt. a(k)) goto 100
      a(k+1)=t
      goto 90
      end
