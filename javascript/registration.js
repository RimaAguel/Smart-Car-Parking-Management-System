 <script>
    
    let btn=document.getElementById('btn')
    btn.addEventListener('click',fun)

    function fun(){
        
  var day = new Date();

  var entrance = day.getHours() + " AM:" + day.getMinutes() + ":" + day.getSeconds();

  let parkingTable = document.getElementById("myTable");


         let name=document.getElementById("name").value
        let plate = document.getElementById("pl-num").value;
        let color = document.getElementById("carC").value;
        let phoneNum=document.getElementById("telNum").value;

var row = parkingTable.insertRow();
var numRow = document.getElementById('myTable').rows.length;

row.innerHTML = `
<td>${name}</td>
<td>${plate}</td>
<td>${color}</td>
<td>${phoneNum}</td>
<td>${entrance}</td>
`;

row.id = numRow;
var col= row.insertCell();

var rem = document.createElement('input');
    rem.type = "button";
    rem.value = "x";
    rem.style = "background-color:red;color:black;border-radius:7px;width:50px;height:30px"
    col.appendChild(rem);

    rem.onclick = 
    function del() {
       document.getElementById(numRow).remove(numRow);
    };
    
};