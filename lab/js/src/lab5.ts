
document.addEventListener("DOMContentLoaded", () => {
    console.log("Страница загрузилась");

    function getCurrentDate(): void { 
        console.log(Date.now()); 
    }

    setTimeout(() => {
        clearInterval(intervalDescriptor);//очистка таймера
        getCurrentDate();

        const intFunction = extFunction("abababbab");
        intFunction("lolololol");
    }, 1000*60);//таймер на 5 сек

    let sec = 5;
    let intervalDescriptor = setInterval(() => {
        console.log("Прошла(-о): " + sec + " секунд(-ы)(-а).");
        // if (sec >= 60) {
        //     clearInterval(intervalDescriptor);
        // }

        sec += 5; // Увеличиваем счетчик на 5 секунд
    }, 5000);

    function extFunction(x: string) {
        console.log("Внешняя фунция вводим строку: " + x);
        return (y: string) => console.log("Возврат результата в виде функции с замыканием на внешнюю функцию: " + (x + y));
    }
});