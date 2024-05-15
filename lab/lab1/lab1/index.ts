function loadData() {
    let xhr = new XMLHttpRequest();
    xhr.open('GET', 'data.json', false);
    xhr.send();
    if (xhr.status !== 200) {
        alert('Ошибка ' + xhr.status + ': ' + xhr.statusText);

    } else {
        alert(xhr.responseText);
    }
}

loadData();