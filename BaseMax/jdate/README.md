# jdate

A free software for Jalali and shamsi date to get current date in jalali calendar.

## Features

- Convert date to jalali, shamsi calendar and getting current date
- Getting name of days (day of week)
- Getting name of months

## Using

#### $ jdate --auto
```
1399/1/3 - فروردين - يکشنبه
```

#### $ jdate 2020 03 22
```
1399/1/3 - فروردين - يکشنبه
```

## Compiling

```
$ cd src/
$ gcc jdate.c -o jdate -O3
$ move jdate /usr/bin/
```

## Dependencies

It will use `$ date` if you pass `--auto` argument.

## Jalali calendar help

<div id="maintext">

<h1>The Persian Calendar</h1>

<p>The Persian calendar is a solar calendar with a starting point that matches that of the Islamic
calendar. Apart from that, the two calendars are not related. The origin of the Persian calendar can
be traced back to the 11th century when a group of astronomers (including the well-known poet Omar
Khayyam, pictured above) created what is known as the Jalaali calendar. However, a number of changes have been made
to the calendar since then.</p>

<p>The current calendar has been used in Iran since 1925 and in Afghanistan since 1957. However,
Afghanistan used the Islamic calendar in the years 1999-2002.</p>

<h2><a name="look">What does a Persian year look like?</a></h2>

<p> The names and lengths of the 12 months that comprise the Persian year are:</p>

<table class="blank">
  <tbody><tr>
    <td class="right spnarrow">1.</td>
    <td class="spnarrow">Farvardin</td>
    <td class="spwide">(31 days)</td>
    <td class="right spnarrow">7.</td>
    <td class="spnarrow">Mehr</td>
    <td>(30 days)</td>
  </tr>
  
  <tr>
    <td class="right spnarrow">2.</td>
    <td class="spnarrow">Ordibehesht</td>
    <td class="spwide">(31 days)</td>
    <td class="right spnarrow">8.</td>
    <td class="spnarrow">Aban</td>
    <td>(30 days)</td>
  </tr>

  <tr>
    <td class="right spnarrow">3.</td>
    <td class="spnarrow">Khordad</td>
    <td class="spwide">(31 days)</td>
    <td class="right spnarrow">9.</td>
    <td class="spnarrow">Azar</td>
    <td>(30 days)</td>
  </tr>

  <tr>
    <td class="right spnarrow">4.</td>
    <td class="spnarrow">Tir</td>
    <td class="spwide">(31 days)</td>
    <td class="right spnarrow">10.</td>
    <td class="spnarrow">Day</td>
    <td>(30 days)</td>
  </tr>

  <tr>
    <td class="right spnarrow">5.</td>
    <td class="spnarrow">Mordad</td>
    <td class="spwide">(31 days)</td>
    <td class="right spnarrow">11.</td>
    <td class="spnarrow">Bahman</td>
    <td>(30 days)</td>
  </tr>

  <tr>
    <td class="right spnarrow">6.</td>
    <td class="spnarrow">Shahrivar</td>
    <td class="spwide">(31 days)</td>
    <td class="right spnarrow">12.</td>
    <td class="spnarrow">Esfand</td>
    <td>(29/30 days)</td>
  </tr>
</tbody></table>


<p>(Due to different transliterations of the Persian alphabet, other spellings of the months are
possible.) In Afghanistan the months are named differently.</p>

<p> The month of Esfand has 29 days in an ordinary year, 30 days in a leap year.</p>

<h2><a name="begin">When does the Persian year begin?</a></h2>

<p>The Persian year starts at vernal equinox. If the astronomical vernal equinox falls before noon
(Tehran true time) on a particular day, then that day is the first day of the year. If the
astronomical vernal equinox falls after noon, the following day is the first day of the year.</p>

<h2><a name="count">How does one count years?</a></h2>

<p> As in the Islamic calendar, years are counted since <a href="#count">Mohammed’s
emigration to Medina</a> in AD&nbsp;622. At vernal equinox of that year, AP&nbsp;1 started (AP =
Anno Persico/Anno Persarum = Persian year).</p>

<p>Note that contrary to the Islamic calendar, the Persian calendar counts solar years. In the year
AD&nbsp;2011 we have therefore witnessed the start of Persian year 1390, but the start of Islamic
year 1432.</p>

<h2><a name="leap">What years are leap years?</a></h2>

<p>Since the Persian year is defined by the astronomical vernal equinox, the answer is simply: Leap
years are years in which there are 366 days between two Persian new year’s days.</p>

<p>However, basing the Persian calendar purely on an astronomical observation of the vernal equinox
is rejected by many, and a few mathematical rules for determining the length of the year have been
suggested.</p>

<p>The most popular (and complex) of these is probably the following:</p>

<p>
The calendar is divided into periods of 2820 years. These periods are
then divided into 88 cycles whose lengths follow this pattern:</p>

<p class="indent">
29, 33, 33, 33, 29, 33, 33, 33, 29, 33, 33, 33, ...
</p>

<p>This gives 2816 years. The total of 2820 years is achieved by extending the last cycle by 4 years
(for a total of 37 years).</p>

<p>If you number the years within each cycle starting with 0, then leap years are the years that are
divisible by 4, except that the year 0 is not a leap year.</p>

<p>So within, say, a 29 year cycle, this is the leap year pattern:</p>

<table style="margin: auto;">
  <tbody><tr>
    <th class="center spnarrow">Year</th>
    <th class="left spxwide">Type</th>
    <th class="center spnarrow">Year</th>
    <th class="left spxwide">Type</th>
    <th class="center spnarrow">Year</th>
    <th class="left spxwide">Type</th>
    <th class="center spnarrow">Year</th>
    <th class="left spxwide">Type</th>
  </tr>

  <tr>
    <td class="center spnarrow">0</td>
    <td class="left spxwide">Ordinary</td>
    <td class="center spnarrow">8</td>
    <td class="left spxwide">Leap</td>
    <td class="center spnarrow">16</td>
    <td class="left spxwide">Leap</td>
    <td class="center spnarrow">24</td>
    <td class="left spxwide">Leap</td>
  </tr>

  <tr>
    <td class="center spnarrow">1</td>
    <td class="left spxwide">Ordinary</td>
    <td class="center spnarrow">9</td>
    <td class="left spxwide">Ordinary</td>
    <td class="center spnarrow">17</td>
    <td class="left spxwide">Ordinary</td>
    <td class="center spnarrow">25</td>
    <td class="left spxwide">Ordinary</td>
  </tr>

  <tr>
    <td class="center spnarrow">2</td>
    <td class="left spxwide">Ordinary</td>
    <td class="center spnarrow">10</td>
    <td class="left spxwide">Ordinary</td>
    <td class="center spnarrow">18</td>
    <td class="left spxwide">Ordinary</td>
    <td class="center spnarrow">26</td>
    <td class="left spxwide">Ordinary</td>
  </tr>

  <tr>
    <td class="center spnarrow">3</td>
    <td class="left spxwide">Ordinary</td>
    <td class="center spnarrow">11</td>
    <td class="left spxwide">Ordinary</td>
    <td class="center spnarrow">19</td>
    <td class="left spxwide">Ordinary</td>
    <td class="center spnarrow">27</td>
    <td class="left spxwide">Ordinary</td>
  </tr>

  <tr>
    <td class="center spnarrow">4</td>
    <td class="left spxwide">Leap</td>
    <td class="center spnarrow">12</td>
    <td class="left spxwide">Leap</td>
    <td class="center spnarrow">20</td>
    <td class="left spxwide">Leap</td>
    <td class="center spnarrow">28</td>
    <td class="left spxwide">Leap</td>
  </tr>

  <tr>
    <td class="center spnarrow">5</td>
    <td class="left spxwide">Ordinary</td>
    <td class="center spnarrow">13</td>
    <td class="left spxwide">Ordinary</td>
    <td class="center spnarrow">21</td>
    <td class="left spxwide">Ordinary</td>
  </tr>

  <tr>
    <td class="center spnarrow">6</td>
    <td class="left spxwide">Ordinary</td>
    <td class="center spnarrow">14</td>
    <td class="left spxwide">Ordinary</td>
    <td class="center spnarrow">22</td>
    <td class="left spxwide">Ordinary</td>
  </tr>

  <tr>
    <td class="center spnarrow">7</td>
    <td class="left spxwide">Ordinary</td>
    <td class="center spnarrow">15</td>
    <td class="left spxwide">Ordinary</td>
    <td class="center spnarrow">23</td>
    <td class="left spxwide">Ordinary</td>
  </tr>
</tbody></table>

<p> This gives a total of 683 leap years every 2820 years, which corresponds to an average year
length of 365&thinsp;<sup>683</sup>/<sub>2820</sub> = 365.24220 days. This is a better approximation to the
tropical year than the 365.2425 days of the Gregorian calendar.</p>

<p>The current 2820 year period started in the year AP&nbsp;475 (AD&nbsp;1096).</p>

<p>This “mathematical” calendar currently coincides closely with the purely astronomical
calendar. In the years between AP&nbsp;1244 and 1531 (AD&nbsp;1865 and 2152) a discrepancy of one
day is seen twice, namely in AP&nbsp;1404 and 1437 (starting at vernal equinox of AD&nbsp;2025 and
2058). However, outside this period, discrepancies are more frequent.</p>
         </div>
         
---------

# Max Base

My nickname is Max, Programming language developer, Full-stack programmer. I love computer scientists, researchers, and compilers. ([Max Base](https://maxbase.org/))

## Asrez Team

A team includes some programmer, developer, designer, researcher(s) especially Max Base.

[Asrez Team](https://www.asrez.com/)
