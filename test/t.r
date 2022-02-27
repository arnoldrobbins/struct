# a fortran subroutine (from r.c. singleton, algorithm 347, an efficient
# algorithm for sorting with minimal storage, comm. acm 12, 3 (march 1969),
# p. 186, with some added comments):
subroutine sort(a,ii,jj)
# variation on quicksort sorts array a into increasing order from a(ii) to a(jj)
# arrays iu(k) and il(k) permit sorting up to 2**(k+1)-1 elements
dimension a(1),iu(16),il(16)
integer a,t,tt
m = 1
i = ii
j = jj
repeat {
	if (i < j)
		go to 10
	repeat {
# find next segment to be sorted
		m = m-1
		if (m == 0)
			break 2
		i = il(m)
		j = iu(m)
		while (j - i >= 11) {
# set t to median of a(i), a((i+j)/2), a(j)
			10  k = i
			ij = (j+i)/2
			t = a(ij)
			if (a(1) > t) {
				a(ij) = a(i)
				a(i) = t
				t = a(ij)
				}
			l = j
			if (a(j) < t) {
				a(ij) = a(j)
				a(j) = t
				t = a(ij)
				if (a(i) > t) {
					a(ij) = a(i)
					a(i) = t
					t = a(ij)
					}
				}
			repeat {
# use t to split segment
				l = l-1
				if (a(l) <= t) {
					tt = a(l)
					repeat
						k = k+1
						until(a(k) >= t)
					if (k > l)
						break 1
					a(l) = a(k)
					a(k) = tt
					}
				}
# stack one segment to be sorted later
			if (l - i <= j - k) {
				il(m) = k
				iu(m) = j
				j = l
				m = m+1
				}
			else {
				il(m) = i
				iu(m) = l
				i = k
				m = m + 1
				}
			}
# sort small segments
		if (i == ii)
			break 1
		i = i-1
		repeat {
			i = i+1
			if (i == j)
				break 1
			t = a(i+1)
			if (a(i) > t) {
				k = i
				repeat {
					a(k+1) = a(k)
					k = k-1
					}
					until(t >= a(k))
				a(k+1) = t
				}
			}
		}
	}
return
end



