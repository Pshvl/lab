document.addEventListener("DOMContentLoaded", function () {
    console.log("Страница загрузилась");
    function getCurrentDate() {
        console.log(Date.now());
    }
    setTimeout(function () {
        clearInterval(intervalDescriptor); //очистка таймера
        getCurrentDate();
        var intFunction = extFunction("abababbab");
        intFunction("lolololol");
    }, 1000 * 60); //таймер на 5 сек
    var sec = 5;
    var intervalDescriptor = setInterval(function () {
        console.log("Прошла(-о): " + sec + " секунд(-ы)(-а).");
        // if (sec >= 60) {
        //     clearInterval(intervalDescriptor);
        // }
        sec += 5; // Увеличиваем счетчик на 5 секунд
    }, 5000);
    function extFunction(x) {
        console.log("Внешняя фунция вводим строку: " + x);
        return function (y) { return console.log("Возврат результата в виде функции с замыканием на внешнюю функцию: " + (x + y)); };
    }
});
