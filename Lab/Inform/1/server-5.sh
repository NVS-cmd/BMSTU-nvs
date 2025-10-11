while true; do
  nc -l -p 8080 -q 1 | while read line; do
    echo "Получено сообщение: $line"
    echo "Сообщение получено"
  done | nc -l -p 8080 -q 1
done
