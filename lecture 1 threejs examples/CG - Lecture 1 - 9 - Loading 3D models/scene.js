// Create scene
var scene = new THREE.Scene();

// Create camera
var camera = new THREE.PerspectiveCamera(
    75,     // fov - Camera frustum vertical field of view
    window.innerWidth / window.innerHeight, // aspect - Camera frustum aspect ratio
    0.1,   // near - Camera frustum near plane
    1000); // far - Camera frustum far plane

// Create renderer
var renderer = new THREE.WebGLRenderer({ antialias: true, alpha: true });
renderer.setSize(window.innerWidth, window.innerHeight);
document.body.appendChild(renderer.domElement);

var material = new THREE.MeshPhongMaterial({ color: 0xcccccc, ambient: 0x444444, side: THREE.DoubleSide });
var loader = new THREE.JSONLoader();
loader.load("teapot.js", function(geometry, materials) {
    mesh = new THREE.Mesh(geometry, material);
    scene.add(mesh);
});

// Define light

var ambient = new THREE.AmbientLight(0x404040);
scene.add(ambient);

// Directional - KEY LIGHT
keyLight = new THREE.DirectionalLight(0xdddddd, .7);
keyLight.position.set(-80, 60, 80);
scene.add(keyLight);

//keyLightHelper = new THREE.DirectionalLightHelper(keyLight, 15);
//scene.add(keyLightHelper);

// Directional - FILL LIGHT
fillLight = new THREE.DirectionalLight(0xdddddd, .3);
fillLight.position.set(80, 40, 40);
scene.add(fillLight);

//fillLightHelper = new THREE.DirectionalLightHelper(fillLight, 15);
//scene.add(fillLightHelper);

// Directional - RIM LIGHT
rimLight = new THREE.DirectionalLight(0xdddddd, .6);
rimLight.position.set(-20, 80, -80);
scene.add(rimLight);

// Move camera from center
camera.position.x = 0;
camera.position.y = 30;
camera.position.z = 100;

// Import camera control and rotation library
controls = new THREE.OrbitControls(camera); 
controls.autoRotate = true;
controls.autoRotateSpeed = 2;
controls.noKeys = true;

var render = function() {
    requestAnimationFrame(render);

    controls.update();
    renderer.render(scene, camera);
}

render();
