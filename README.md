# robot-odtwarzacz
Instrukcje i kod źródłowy do robota odtwarzającego dźwięki w przypadku otwarcia czegokolwiek





**Jak stworzyć robota?**


Ja do stworzenia robota wykorzystałem płytkę NodeMcu v3, bo akurat nie miałem pod ręką żadnego wolnego arduino. Płytka NodeMcu to w zasadzie arduino na sterydach (moduł WiFi, więcej pamięci), ale oczywiście można też korzystać ze standardowego arduino. Trzeba jednak pamiętać, że NodeMcu bazuje na logice 3.3V, a arudino 5V.



**Potrzebne rzeczy:**


- Płytka z mikrokontrolerem i programatorem
- Moduł odtwarzający (w moim przypadku DfPlayer Mini)
- Głośnik (ja użyłem JBL GO, chociaż prawdę mówiąc znacznie łatwiej będzie użyć zwykłego głośnika, DfPlayer obsługuje głośniki do 3W, więc jest to moc w zupełności wystarczająca)
- Karta pamięci
- Kontaktron, lub przycisk (chodzi o coś, co będzie nam wyzwalało nasz dźwięk)
- Płytka stykowa i kabelki
- Zasilacz (wystarczy zwykła 'kostka' do ładowania telefonu na 5V)

**Schemat połączeń:**

Zaczynamy od podpięcia naszego kontraktronu, lub innego wyzwalacza. Jedną końcówkę wpinamy w port D8 (GPIO15), a drugą w port 3V, lub 5V, w zależności od logiki płytki z której korzystasz. Następnie podłączymy nasz moduł odtwarzający. Jego schemat jest dostępny w internecie. Porty RX i TX, z uwagi na ograniczone możliwości NodeMcu, wpinamy w porty - odpowiednio D2 i D1. Podłączamy zasilanie i uziemienie. Co do podłączenia głośnika - jeżeli używamy głośnika aktywnego (z wbudowanym zasilaniem, akumulatorem), będziemy korzystać z portów DAC_L i DAC_R naszego modułu odtwarzającego. Jeżeli jednak korzystamy z głośnika pasywnego do 3W, używamy portów SPK_1 i SPK_2. Podłączamy głośnik i zasilanie płytki i jesteśmy gotowi do działania ;)

**Kod:**

Kod nie jest najlepszej klasy, ale działa. Korzystałem z IDE Arduino, żeby móc od razu wgrywać na płytkę. Gdyby ktoś miał ochotę na jakiś Pull Request - jestem bardzo otwarty :))


