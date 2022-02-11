f = open('index.html', 'r')
w = open('output.html', 'w')

line = f.readline()

while line:
  if 'img' in line:
    index = line.index('src')
    start = line.index('"', index)
    end = line.index('"', start+1)
    line = line[:start+1] + "<%= require('{}')%>".format(line[start+1:end]) + line[end:]
  w.write(line)
  line = f.readline()