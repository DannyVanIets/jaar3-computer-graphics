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

// Create geometry
var geometry = new THREE.Geometry();
geometry.vertices.push(new THREE.Vector3(0.0, 0.0, 0.0));
geometry.vertices.push(new THREE.Vector3(1.0, 0.0, 0.0));
geometry.vertices.push(new THREE.Vector3(1.0, 1.0, 0.0));
//geometry.vertices.push(new THREE.Vector3(0.0, 1.0, 0.0));

var uvs = [];
uvs.push(new THREE.Vector2(0.0, 0.0));
uvs.push(new THREE.Vector2(1.0, 0.0));
uvs.push(new THREE.Vector2(0.0, 1.0)); // has to be 1.0, 1.0
//uvs.push(new THREE.Vector2(0.0, 1.0));  

// Generate faces
geometry.faces.push(new THREE.Face3(0, 1, 2));
//geometry.faces.push(new THREE.Face3(2, 3, 0));
geometry.faceVertexUvs[ 0 ].push([ uvs[0], uvs[1], uvs[2] ]);
//geometry.faceVertexUvs[ 0 ].push([ uvs[2], uvs[3], uvs[0] ]);
        
var material = new THREE.MeshBasicMaterial({map: THREE.ImageUtils.loadTexture('Yellobrk.bmp')});
var cube = new THREE.Mesh(geometry, material);
scene.add(cube);

// Define light
var light = new THREE.DirectionalLight(0xdddddd, 1);
light.position.set(0, 0, 1);
scene.add(light);

camera.position.x = .5;
camera.position.y = .5;
camera.position.z = 1;

var render = function() {
    requestAnimationFrame(render);

    renderer.render(scene, camera);
}

render();
