//brainfuck (http://www.hevanet.com/cristofd/brainfuck/) interpreter
//made 2003 by Daniel B Cristofani (cristofdathevanetdotcom) based on the
//one at (http://justice.loyola.edu/~mcoffey/pr/5k/) and licensed under GPL

function x(y) {
  c = y[0].value;
  i = y[2].value;
  p = j = z = c.length;
  a = new Array(z + 32768)
  for (g = 0;
    (k = c.charAt(--j)) == '[' ? a[a[j] = a[--g]] = j : j;) k == ']' ? a[g++] = j : 0
  for (k = 0; j < z; j++) {
    h = c.charCodeAt(j) - 40;
    p > g ? a[g = p] = 0 : 0
    j = h + 2 * !(a[p += h ^ 20 ? h == 22 : -1] += h ^ 5 ? h == 3 : -1) ^ 53 ? j : a[j]
    j -= h ^ 4 | k == i.length ? 0 : (a[p] = i.charCodeAt(k++)) == 13
    y[3].value += h ^ 6 ? "" : String.fromCharCode(a[p])
  }
}
